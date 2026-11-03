#include <array>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>

#include <TApplication.h>
#include <TCanvas.h>
#include <TGraph.h>
#include <TLegend.h>
#include <TMultiGraph.h>
#include <TStyle.h>
#include <TAxis.h>
#include <TSystem.h>
#include <TLatex.h>

#include "Garfield/ComponentAnalyticField.hh"
#include "Garfield/DriftLineRKF.hh"
#include "Garfield/MediumMagboltz.hh"
#include "Garfield/Sensor.hh"
#include "Garfield/TrackHeed.hh"
#include "Garfield/ViewCell.hh"
#include "Garfield/ViewDrift.hh"
#include "Garfield/ViewField.hh"


#include <algorithm>
#include <cmath>
#include <vector>

using namespace Garfield;


// Move this out of main() to namespace scope so the function can use it.
struct IonTrajectory {
  std::vector<double> xs, ys, ts;
};

// Resample onto the global grid t = k * dt (absolute time, same origin for all ions).
// If keepEnds is true, the true start and end points are also kept, so the ion's
// exact creation and arrival times are preserved (spacing at the ends is then irregular).
IonTrajectory Resample(const IonTrajectory& in, const double dt,
                       const bool keepEnds = false) {
  IonTrajectory out;
  const size_t n = in.ts.size();
  if (n < 2 || dt <= 0.) return out;

  const double t0 = in.ts.front();
  const double t1 = in.ts.back();

  // Linear interpolation at time t (t must lie within [t0, t1]).
  auto emit = [&](const double t) {
    auto it = std::upper_bound(in.ts.begin(), in.ts.end(), t);
    size_t i = static_cast<size_t>(it - in.ts.begin());
    if (i == 0) i = 1;            // t == t0 edge case
    if (i >= n) i = n - 1;        // t == t1 edge case
    const double tA = in.ts[i - 1], tB = in.ts[i];
    const double f = tB > tA ? (t - tA) / (tB - tA) : 0.;
    out.ts.push_back(t);
    out.xs.push_back(in.xs[i - 1] + f * (in.xs[i] - in.xs[i - 1]));
    out.ys.push_back(in.ys[i - 1] + f * (in.ys[i] - in.ys[i - 1]));
  };

  // Integer grid indices avoid accumulating floating-point error.
  const long kMin = static_cast<long>(std::ceil(t0 / dt));
  const long kMax = static_cast<long>(std::floor(t1 / dt));

  if (keepEnds && kMin * dt > t0) emit(t0);
  for (long k = kMin; k <= kMax; ++k) emit(k * dt);
  if (keepEnds && kMax * dt < t1) emit(t1);

  return out;
}

int main(int argc, char* argv[]) {
  TApplication app("app", &argc, argv);

  // --- Gas -----------------------------------------------------------
  MediumMagboltz gas;
  std::ifstream f("He_50_C2H6_50.gas");
  if (!f.good()) {
    std::cerr << "he_c2h6.gas not found - run ./gas first.\n";
    return 1;
  }
  gas.LoadGasFile("He_50_C2H6_50.gas");

  // Ion transport (DriftIon) uses tabulated *mobilities*, not the Magboltz
  // electron-transport tables, so a separate ion-mobility file has to be
  // loaded, or DriftIon() will fail / return false for every ion.
  // Garfield++ ships a handful of these under share/Garfield/Data; there is
  // no exact He/C2H6-mixture table, so as an approximation we use He+ in He
  // (He+ dominates the primary ionisation in a He-rich mixture). Swap this
  // for a better match if you have one (e.g. from LXCat-derived data).
  const char* install = std::getenv("GARFIELD_INSTALL");
  if (!install) {
    std::cerr << "GARFIELD_INSTALL not set - cannot locate ion mobility data.\n";
    return 1;
  }
  const std::string ionMobilityFile =
      std::string(install) + "/share/Garfield/Data/IonMobility_He+_He.txt";
  if (!gas.LoadIonMobility(ionMobilityFile)) {
    std::cerr << "Could not load ion mobility file " << ionMobilityFile << "\n";
    return 1;
  }

  // --- Geometry and field -------------------------------------------
  const double rTube = 1.82;        // cm
  const double SenseWireDiameter = 30.e-4;  // cm (30 um)
  const double FieldWireDiameter = 126.e-4;  // cm (126 um)
  const double vWire = 2300.;      // V
  const double vField = 0.;      // V (tube grounded)
  const double pitch = 0.91;         // cm, distance between sense wires

  ComponentAnalyticField cmp;
  cmp.SetMedium(&gas);
  cmp.AddWire(-pitch, pitch, FieldWireDiameter, vField, "f0");
  cmp.AddWire(pitch, pitch, FieldWireDiameter, vField, "f1");
  cmp.AddWire(0, pitch, FieldWireDiameter, vField, "f2");
  cmp.AddWire(pitch, -pitch, FieldWireDiameter, vField, "f3");
  cmp.AddWire(-pitch, -pitch, FieldWireDiameter, vField, "f4");
  cmp.AddWire(0, -pitch, FieldWireDiameter, vField, "f5");
  cmp.AddWire(pitch, 0, FieldWireDiameter, vField, "f6");
  cmp.AddWire(-pitch, 0, FieldWireDiameter, vField, "f7");

  cmp.AddWire(0, 0, SenseWireDiameter, vWire, "s9");


  cmp.AddTube(rTube, 0., 0, "tube");  // radius, voltage, nEdges=0 -> round

  Sensor sensor;
  sensor.AddComponent(&cmp);

  // --- Plotting -------------------------------------------------------
  TCanvas* canvas = new TCanvas("cDrift", "Drift tube", 700, 700);
  ViewCell cellView;
  cellView.SetCanvas(canvas);
  cellView.SetComponent(&cmp);

  ViewDrift driftView;
  driftView.SetCanvas(canvas);

  // --- Particle track (Heed) and electron/ion drift ---------------------
  TrackHeed track(&sensor);
  track.SetParticle("muon");
  track.SetMomentum(1.e9);  // eV/c
  track.EnablePlotting(&driftView);

  // Same DriftLineRKF instance handles electrons AND ions; both get added
  // to driftView automatically because plotting was enabled once below.
  DriftLineRKF drift(&sensor);
  drift.EnablePlotting(&driftView);

  // Muon travelling in +y, passing 0.4 cm to the side of the wire.
  // Arguments: x0, y0, z0, t0, dx, dy, dz.
  track.NewTrack(0.45, -1.6, 0., 0., 0., 1., 0.);

  double xc, yc, zc, tc, ec, extra;
  int nc;
  int nClusters = 0, nElectrons = 0, nIons = 0;
  double firstArrival = 1.e9;  // ns, fastest electron

  double ionTimeSum = 0., ionTimeMin = 1.e9, ionTimeMax = -1.;
  double ionSpeedSum = 0., ionSpeedMin = 1.e9, ionSpeedMax = -1.;

  // Full position-vs-time trajectory of every ion, kept for later analysis
  // or custom plotting. Each ion gets its own set of parallel vectors:
  // xs[k], ys[k], ts[k] together describe the ion's position at drift-line
  // point k (i.e. xs[k] and ys[k] are the position at time ts[k]).
  std::vector<IonTrajectory> ionTrajectories;
  while (track.GetCluster(xc, yc, zc, tc, nc, ec, extra)) {
    ++nClusters;
    for (int j = 0; j < nc; ++j) {
      double xe, ye, ze, te, ee, dxe, dye, dze;
      track.GetElectron(j, xe, ye, ze, te, ee, dxe, dye, dze);
      ++nElectrons;

      // --- Electron -----------------------------------------------
      drift.DriftElectron(xe, ye, ze, te);
      double xf, yf, zf, tf;
      int status;
      drift.GetEndPoint(xf, yf, zf, tf, status);
      if (tf - te < firstArrival) firstArrival = tf - te;

      // --- Ion left behind at the same ionisation site --------------
      // (the electron and its parent ion are created at the same point;
      // the ion is essentially stationary compared to diffusion until the
      // field starts pulling it away, so xe,ye,ze,te is a fine starting
      // point for it too)
      if (drift.DriftIon(xe, ye, ze, te)) {
        ++nIons;
        double xi, yi, zi, ti;
        int istatus;
        drift.GetEndPoint(xi, yi, zi, ti, istatus);
        const double ionTime = ti - te;                 // ns
        const double pathLength = drift.GetPathLength(); // cm
        const double avgSpeed = pathLength > 0. && ionTime > 0.
                                     ? pathLength / ionTime  // cm/ns
                                     : 0.;

        ionTimeSum += ionTime;
        ionTimeMin = std::min(ionTimeMin, ionTime);
        ionTimeMax = std::max(ionTimeMax, ionTime);
        ionSpeedSum += avgSpeed;
        ionSpeedMin = std::min(ionSpeedMin, avgSpeed);
        ionSpeedMax = std::max(ionSpeedMax, avgSpeed);

        // Copy this ion's (x, y, t) points out of the DriftLineRKF object
        // now, before the next DriftElectron/DriftIon call overwrites them.
        IonTrajectory traj;
        const size_t nPoints = drift.GetNumberOfDriftLinePoints();
        traj.xs.reserve(nPoints);
        traj.ys.reserve(nPoints);
        traj.ts.reserve(nPoints);
        for (size_t k = 0; k < nPoints; ++k) {
          double xp, yp, zp, tp;
          drift.GetDriftLinePoint(k, xp, yp, zp, tp);
          traj.xs.push_back(xp);
          traj.ys.push_back(yp);
          traj.ts.push_back(tp);
        }
        ionTrajectories.push_back(std::move(traj));
      }
    }
  }

  std::cout << "Clusters: " << nClusters << ", primary electrons: "
            << nElectrons << ", ions drifted: " << nIons << "\n"
            << "Drift time of first electron: " << firstArrival << " ns\n";
  if (nIons > 0) {
    std::cout << "Ion drift time  [ns]:  min = " << ionTimeMin
              << "  max = " << ionTimeMax
              << "  mean = " << ionTimeSum / nIons << "\n"
              << "Ion avg. speed [cm/ns]: min = " << ionSpeedMin
              << "  max = " << ionSpeedMax
              << "  mean = " << ionSpeedSum / nIons
              << "   (i.e. " << (ionSpeedSum / nIons) * 1.e5
              << " cm/us)\n";
  }

  // const double dt = 5.;  // ns, pick based on your ion drift times
  // std::vector<IonTrajectory> resampled;
  // resampled.reserve(ionTrajectories.size());
  // for (const auto& traj : ionTrajectories) {
  //   resampled.push_back(Resample(traj, dt));
  // }

  // std::cout << "resampled time size: " << resampled.size() << "\n";
  //   // for each time step in resamples. Take all ions positions and calculate the space charge field at that time step. Then plot the field.
  // const double xmin = -0.182, xmax = 0.182;
  // const double ymin = -0.182, ymax = 0.182;

  // const char* gifName = "../plots/ion_positions.gif";
  // const int delay = 10;  // 10 * 10 ms = 100 ms per frame

  // gSystem->Unlink(gifName);  // remove old file, otherwise frames get appended to it

  // size_t lastK = 0;
  // bool haveFrame = false;

  // TCanvas c("c", "Ion positions", 500, 500);


  // for (size_t k = 0; true; k += 50) {
  //   std::vector<double> xs, ys;
  //   for (const auto& traj : resampled) {
  //     if (k < traj.ts.size()) {
  //       xs.push_back(traj.xs[k]);
  //       ys.push_back(traj.ys[k]);
  //     }
  //   }
  //   std::int64_t act_time = k * dt;
  //   if (xs.empty()) break;
  //   std::cout << "Time step " << act_time << ": " << xs.size() << " ions\n";

  //   c.Clear();
  //   TGraph g(xs.size(), xs.data(), ys.data());
  //   g.SetTitle(Form("Ion positions, step %zu; x [cm]; y [cm]", k));
  //   g.SetMarkerStyle(20);
  //   g.SetMarkerSize(0.8);
  //   g.SetMarkerColor(kRed);

  //   //add wires 
  //   std::vector<double> wire_xs = {-0.091, 0.091, 0, 0.091, -0.091, 0, 0.091, -0.091, 0};
  //   std::vector<double> wire_ys = {0.091, 0.091, 0.091, -0.091, -0.091, -0.091, 0, 0, 0};
  //   TGraph g_wires(wire_xs.size(), wire_xs.data(), wire_ys.data());
  //   g_wires.SetMarkerStyle(20);
  //   g_wires.SetMarkerSize(1);
  //   g_wires.SetMarkerColor(kBlack);

  //   // add circle
  //   static const int nCirclePoints = 100;
  //   std::vector<double> circle_xs(nCirclePoints);
  //   std::vector<double> circle_ys(nCirclePoints);
  //   for (int i = 0; i < nCirclePoints; ++i) {
  //     double angle = 2 * M_PI * i / nCirclePoints;
  //     circle_xs[i] = rTube * cos(angle);
  //     circle_ys[i] = rTube * sin(angle);
  //   }
  //   TGraph g_circle(nCirclePoints, circle_xs.data(), circle_ys.data());
  //   g_circle.SetLineColor(kBlue);
  //   g_circle.SetLineWidth(2);

  //   g.GetXaxis()->SetLimits(xmin, xmax);
  //   g.GetYaxis()->SetRangeUser(ymin, ymax);
  //   g.Draw("AP");
  //   g_wires.Draw("P SAME");
  //   g_circle.Draw("L SAME");

  //   TLatex label;
  //   label.SetTextSize(0.035);
  //   label.SetTextAlign(13);  // left-top aligned
  //   label.DrawLatexNDC(0.22, 0.90, Form("t = %lld ns", act_time));     
  //   label.DrawLatexNDC(0.22, 0.85, Form("N_{muons} = %zu", xs.size()));

  //   c.Update();
  //   // Append this frame to the GIF
  //   c.Print(Form("%s+%d", gifName, delay));
  //   haveFrame = true;
  // }

  // // Mark the animation as finished so it loops forever
  // if (haveFrame) {
  //   c.Clear();
  //   c.Print(Form("%s++", gifName));  // see note below
  // }


  // --- Draw -------------------------------------------------------------
  constexpr bool twod = true;
  constexpr bool drawaxis = false;  // the cell view already draws the axes

  canvas->cd();
  cellView.Plot2d();                // wires + tube wall + axes
  driftView.Plot(twod, drawaxis);   // tracks and drift lines on top
  canvas->Update();

  app.Run(true);
}