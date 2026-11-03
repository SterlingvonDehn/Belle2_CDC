// avalanche_tracking.C
//
// Heed muon track -> AvalancheMicroscopic for every primary electron
// -> one ion per avalanche electron (created where that electron was born)
// -> DriftLineRKF::DriftIon for the ions.
//
// Recorded per primary electron (TTree "avalanches"):
//   gain, avalanche duration, creation position, nearest sense wire,
//   how many electrons end on a sense wire, whether the size limit was hit.
// Recorded per drifted ion (TTree "ions"):
//   birth position/time, distance to nearest sense wire, ion drift time,
//   weight (macro-ion multiplicity).
// Plus summary histograms, and (optionally) a GIF of the ion field.
//
// Units: cm, ns, V, eV (Garfield++ defaults).
//
// Build (same way as your other script), e.g. with CMake linking Garfield::Garfield,
// or run through ROOT with the Garfield libraries loaded.

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <TApplication.h>
#include <TAxis.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TGraph.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TLatex.h>
#include <TStyle.h>
#include <TSystem.h>
#include <TTree.h>

#include "Garfield/AvalancheMicroscopic.hh"
#include "Garfield/ComponentAnalyticField.hh"
#include "Garfield/DriftLineRKF.hh"
#include "Garfield/MediumMagboltz.hh"
#include "Garfield/Sensor.hh"
#include "Garfield/TrackHeed.hh"

using namespace Garfield;

// ---------------------------------------------------------------------------
// User settings
// ---------------------------------------------------------------------------
namespace cfg {
const std::string gasFile = "/Users/sterlingvondehn/Documents/BelleII/BelleII_Drift_Chambers/DriftChamberSim/gas_files/He_90_C4H10_10.gas";
const std::string outDir = "../plots/He_90_C4H10_10";  // output directory (created if missing)

const double rTube = 4.1;                 // cm
// const double rTube_single = 1.82;           // cm
const double senseDiameter = 30.e-4;       // cm
const double fieldDiameter = 126.e-4;      // cm
const double vSense = 1400.;               // V  (start lower than 2000 V: gain!)
const double pitch = 0.91;                // cm

const int nEvents = 1;                     // number of muon tracks
const double trackX = 0.45, trackY = -1.60;  // muon entry point (moves in +y)

const unsigned int avalancheSizeLimit = 20000;  // cap per primary electron
const size_t maxIonsPerPrimary = 1000;  // macro-ion budget per primary

const bool makeGif = true;                // ion-field animation (costly)
const int gifFrames = 250;                 // approximate number of frames
const int nBins = 80;                      // field-map bins per axis

const bool onlygain = false;  // only record gain, not ion drift (faster)
}  // namespace cfg

// ---------------------------------------------------------------------------
// Ion trajectory + resampling onto a global time grid t = k*dt.
// Every trajectory carries the global index k0 of its first sample, so ions
// created at different times line up correctly when frames are built.
// ---------------------------------------------------------------------------
struct IonTrajectory {
  std::vector<double> xs, ys, ts;
  long k0 = 0;     // global grid index of first sample
  double w = 1.;   // number of real ions this macro-ion represents
};

IonTrajectory Resample(const IonTrajectory& in, const double dt) {
  IonTrajectory out;
  out.w = in.w;
  const size_t n = in.ts.size();
  if (n < 2 || dt <= 0.) return out;
  const long kMin = static_cast<long>(std::ceil(in.ts.front() / dt));
  const long kMax = static_cast<long>(std::floor(in.ts.back() / dt));
  out.k0 = kMin;
  for (long k = kMin; k <= kMax; ++k) {
    const double t = k * dt;
    auto it = std::upper_bound(in.ts.begin(), in.ts.end(), t);
    size_t i = static_cast<size_t>(it - in.ts.begin());
    i = std::min(std::max<size_t>(i, 1), n - 1);
    const double tA = in.ts[i - 1], tB = in.ts[i];
    const double f = tB > tA ? (t - tA) / (tB - tA) : 0.;
    out.ts.push_back(t);
    out.xs.push_back(in.xs[i - 1] + f * (in.xs[i] - in.xs[i - 1]));
    out.ys.push_back(in.ys[i - 1] + f * (in.ys[i] - in.ys[i - 1]));
  }
  return out;
}

// ---------------------------------------------------------------------------
// Nearest sense wire (index, distance to its centre).
// ---------------------------------------------------------------------------
void NearestSenseWire(const std::vector<double>& wx,
                      const std::vector<double>& wy, const double x,
                      const double y, int& index, double& dist) {
  index = -1;
  dist = 1.e9;
  for (size_t i = 0; i < wx.size(); ++i) {
    const double d = std::hypot(x - wx[i], y - wy[i]);
    if (d < dist) {
      dist = d;
      index = static_cast<int>(i);
    }
  }
}

int main(int argc, char* argv[]) {
  TApplication app("app", &argc, argv);
  gSystem->mkdir(cfg::outDir.c_str(), true);

  // --- Gas and ion mobility -------------------------------------------
  MediumMagboltz gas;
  {
    std::ifstream f(cfg::gasFile);
    if (!f.good()) {
      std::cerr << cfg::gasFile << " not found - generate it first.\n";
      return 1;
    }
  }
  gas.LoadGasFile(cfg::gasFile);
  gas.SetMaxElectronEnergy(1.e4);  // eV

  const char* install = std::getenv("GARFIELD_INSTALL");
  if (!install) {
    std::cerr << "GARFIELD_INSTALL not set - cannot locate ion mobility data.\n";
    return 1;
  }
  // Approximation: He+ in He. Replace if you have data closer to the mixture.
  const std::string ionFile =
      std::string(install) + "/share/Garfield/Data/IonMobility_He+_He.txt";
  if (!gas.LoadIonMobility(ionFile)) {
    std::cerr << "Could not load ion mobility file " << ionFile << "\n";
    return 1;
  }


  ComponentAnalyticField cmp;
  cmp.SetMedium(&gas);

  // --- Geometry (7x7 grid, 3x3 sense wires, as in your original) ----------
  std::vector<double> senseX, senseY, fieldX, fieldY;
  int nSense = 0, nField = 0;
  for (int ix = -3; ix <= 3; ++ix) {
    for (int iy = -3; iy <= 3; ++iy) {
      const double x = ix * cfg::pitch;
      const double y = iy * cfg::pitch;
      const bool isSense_1 = ((ix == -3 || ix == -1 || ix == 1 || ix == 3) && (iy == 0));
      const bool isSense_2 = ((ix == -2 || ix == 0 || ix == 2) && (iy == -2 || iy == 2));
      const bool isSense = isSense_1 || isSense_2;

      if (isSense) {
        // unique labels s0..s8 (your old formula produced duplicates)
        cmp.AddWire(x, y, cfg::senseDiameter, cfg::vSense,
                    "s" + std::to_string(nSense++));
        senseX.push_back(x);
        senseY.push_back(y);
      } 
      
      else {
        cmp.AddWire(x, y, cfg::fieldDiameter, 0., "f" + std::to_string(nField++));
        fieldX.push_back(x);
        fieldY.push_back(y);
      }
    }
  }

  // // single cell 
  // cmp.AddWire(-cfg::pitch, 0., cfg::fieldDiameter, 0, "s0");
  // cmp.AddWire(cfg::pitch, 0., cfg::fieldDiameter, 0, "s1");
  // cmp.AddWire(0., -cfg::pitch, cfg::fieldDiameter, 0, "s2");
  // cmp.AddWire(0., cfg::pitch, cfg::fieldDiameter, 0, "s3");
  // cmp.AddWire(-cfg::pitch, -cfg::pitch, cfg::fieldDiameter, 0, "s4");
  // cmp.AddWire(-cfg::pitch, cfg::pitch, cfg::fieldDiameter, 0, "s5");
  // cmp.AddWire(cfg::pitch, -cfg::pitch, cfg::fieldDiameter, 0, "s6");
  // cmp.AddWire(cfg::pitch, cfg::pitch, cfg::fieldDiameter, 0, "s7");

  // std::vector<double> fieldX = {-cfg::pitch, cfg::pitch, 0., 0., -cfg::pitch, -cfg::pitch, cfg::pitch, cfg::pitch};
  // std::vector<double> fieldY = {0., 0., -cfg::pitch, cfg::pitch, -cfg::pitch, cfg::pitch, -cfg::pitch, cfg::pitch};

  // cmp.AddWire(0., 0., cfg::senseDiameter, cfg::vSense, "s4");
  // std::vector<double> senseX = {0.};
  // std::vector<double> senseY = {0.};

  cmp.AddTube(cfg::rTube, 0., 0, "tube");

  Sensor sensor;
  sensor.AddComponent(&cmp);

  // --- Transport objects ------------------------------------------------
  TrackHeed track(&sensor);
  track.SetParticle("muon");
  track.SetMomentum(1.e9);  // eV/c

  AvalancheMicroscopic aval;
  aval.SetSensor(&sensor);
  // aval.EnableAvalancheSizeLimit(cfg::avalancheSizeLimit);

  DriftLineRKF drift(&sensor);  // ions only

  // --- Output ----------------------------------------------------------
  TFile outFile((cfg::outDir + "/avalanches.root").c_str(), "RECREATE");

  // Per-primary tree
  int a_event, a_primary, a_gain, a_hitLimit, a_nearestWire, a_nCollected;
  double a_x, a_y, a_t, a_duration, a_wireDist, a_meanBirthDist;
  int a_ni;
  TTree tA("avalanches", "One entry per primary electron");
  tA.Branch("event", &a_event);
  tA.Branch("primary", &a_primary);
  tA.Branch("x", &a_x);
  tA.Branch("y", &a_y);
  tA.Branch("t", &a_t);
  tA.Branch("gain", &a_gain);             // electrons in avalanche (incl. primary)
  tA.Branch("hitLimit", &a_hitLimit);     // 1 if size limit reached (gain biased)
  tA.Branch("duration", &a_duration);     // ns, from start to last endpoint
  tA.Branch("nearestWire", &a_nearestWire);
  tA.Branch("wireDist", &a_wireDist);     // cm, primary to nearest sense wire
  tA.Branch("nCollected", &a_nCollected); // endpoints on a sense wire surface
  tA.Branch("meanBirthDist", &a_meanBirthDist);  // <dist of ion births to wire>
  tA.Branch("nIonsDrifted", &a_ni);

  // Per-ion tree
  double i_x, i_y, i_t, i_wireDist, i_driftTime, i_w;
  int i_event, i_primary, i_wire;
  TTree tI("ions", "One entry per drifted (macro-)ion");
  tI.Branch("event", &i_event);
  tI.Branch("primary", &i_primary);
  tI.Branch("x", &i_x);
  tI.Branch("y", &i_y);
  tI.Branch("t", &i_t);
  tI.Branch("wire", &i_wire);
  tI.Branch("wireDist", &i_wireDist);
  tI.Branch("driftTime", &i_driftTime);
  tI.Branch("weight", &i_w);

  // Histograms
  TH1D hGain("hGain", "Gain per primary electron;electrons per avalanche;entries",
             100, 0., 1.);  // rebinned later
  hGain.SetCanExtend(TH1::kAllAxes);

  TH1D hDur("hDur", "Avalanche duration;#Delta t [ns];entries", 100, 0., 50.);
  hDur.SetCanExtend(TH1::kAllAxes);

  TH1D hBirthR("hBirthR",
               "Electron birth distance to nearest sense wire;r [cm];Electrons (weighted)",
               100, 0., 0.05);

  TH1D hBirthT("hBirthT", "Electron birth time (induced charge buildup);t [ns];Electrons (weighted)",
               200, 0., 1.);
  hBirthT.SetCanExtend(TH1::kAllAxes);
  TH1D hIonDrift("hIonDrift", "Ion drift time;t [ns];ions (weighted)", 100, 0., 1.);
  hIonDrift.SetCanExtend(TH1::kAllAxes);

  double a_tPrimDrift;   // primary electron drift time
  int a_primStatus;
  tA.Branch("primDriftTime", &a_tPrimDrift);
  tA.Branch("primStatus", &a_primStatus);

  TH1D hPrimDrift("hPrimDrift", "Primary electron drift time;t_{end} - t_{birth} [ns];entries", 100, 0., 1.);
  hPrimDrift.SetCanExtend(TH1::kAllAxes);

  TH1D hAvArrival("hAvArrival", "Avalanche electron arrival time;t_{end} - t_{primary birth} [ns];electrons", 100, 0., 1.);
  hAvArrival.SetCanExtend(TH1::kAllAxes);

  TH1D hAvLife("hAvLife", "Avalanche electron lifetime;t_{end} - t_{birth} [ns];electrons", 100, 0., 1.);
  hAvLife.SetCanExtend(TH1::kAllAxes);

  std::vector<IonTrajectory> ionTrajectories;  // only filled if makeGif

  // --- Event loop -------------------------------------------------------
  long totalElectrons = 0, totalIons = 0, nLimited = 0, nPrimariesAll = 0;
  int failedIons = 0;

  for (int ev = 0; ev < cfg::nEvents; ++ev) {
    track.NewTrack(cfg::trackX, cfg::trackY, 0., 0., 0., 1., 0.);

    double xc, yc, zc, tc, ec, extra;
    int nc;
    int primaryIndex = 0;

    while (track.GetCluster(xc, yc, zc, tc, nc, ec, extra)) {
      for (int j = 0; j < nc; ++j) {
        double xe, ye, ze, te, ee, dxe, dye, dze;
        std::cout << "Primary " << primaryIndex << ": ";
        track.GetElectron(j, xe, ye, ze, te, ee, dxe, dye, dze);

        // NearestSenseWire(senseX, senseY, xe, ye, a_nearestWire, a_wireDist);
        // if (a_nearestWire != 4) {
        //   std::cout << "Skipping primary electron at (" << xe << ", " << ye << ") - nearest wire is " << a_nearestWire << "\n";
        //   continue;  // only track avalanches that start in the central cell
        // }

        // ---- Avalanche ------------------------------------------------
        aval.AvalancheElectron(xe, ye, ze, te, 0.1, 0., 0., 0.);
        const size_t ne = aval.GetNumberOfElectronEndpoints();
        std::cout << "gain: " << ne << "\n";


        // calculate the duration of the avalanche and how many electrons end on a sense wire
        // std::cout << "Starting to calculate duration and collected electrons for primary " << primaryIndex << "\n";
        // double tLast = te;
        // a_nCollected = 0;
        // for (size_t i = 0; i < ne; ++i) {
        //   double x0, y0, z0, t0, e0, x1, y1, z1, t1, e1;
        //   int st;
        //   aval.GetElectronEndpoint(i, x0, y0, z0, t0, e0, x1, y1, z1, t1, e1, st);
        //   tLast = std::max(tLast, t1);
        // }
        // std::cout << "Duration for primary " << primaryIndex << ": " << (tLast - te) << " ns\n";
        // hDur.Fill(tLast - te);



        a_event = ev;
        a_primary = primaryIndex;
        a_x = xe;
        a_y = ye;
        a_t = te;
        a_gain = static_cast<int>(ne);
        // a_hitLimit = ne >= cfg::avalancheSizeLimit ? 1 : 0;

        if (cfg::onlygain) {
          a_hitLimit = ne >= cfg::avalancheSizeLimit ? 1 : 0;
          a_duration = 0.;
          a_nCollected = 0;
          a_tPrimDrift = -1.;
          a_primStatus = 0;
          tA.Fill();
          hGain.Fill(a_gain);
          hDur.Fill(a_duration);
          ++nPrimariesAll;
          ++primaryIndex;
          std::cout  << "primary " << primaryIndex
                    << ": gain " << ne
                    << "\n";
          continue;
        }

        // Scan endpoints once: duration + how many end on a sense wire.
        double tLast = te;
        a_nCollected = 0;
        a_tPrimDrift = -1.;
        a_primStatus = 0;
        for (size_t i = 0; i < ne; ++i) {
          double x0, y0, z0, t0, e0, x1, y1, z1, t1, e1;
          int st;
          aval.GetElectronEndpoint(i, x0, y0, z0, t0, e0, x1, y1, z1, t1, e1, st);
          tLast = std::max(tLast, t1);
          int w;
          double d;
          NearestSenseWire(senseX, senseY, x1, y1, w, d);
          if (d < 1.5 * 0.5 * cfg::senseDiameter) ++a_nCollected;

          // primary: starts exactly at the launch point and time
          if (std::abs(t0 - te) < 1.e-9 && std::abs(x0 - xe) < 1.e-9 &&
              std::abs(y0 - ye) < 1.e-9) {
            a_tPrimDrift = t1 - t0;
            a_primStatus = st;
          }

          hAvArrival.Fill(t1 - te);   // when each electron is collected, measured from the primary's birth
          hAvLife.Fill(t1 - t0);      // how long each electron lived after being created

        }
        if (a_tPrimDrift >= 0.) hPrimDrift.Fill(a_tPrimDrift);
    
        a_duration = tLast - te;

        // ---- Ions: one per avalanche electron, born where it was born ----
        // (every endpoint electron has a parent ion, including the primary,
        // whose ion comes from Heed.)
        // const size_t stride =
        //     std::max<size_t>(1, ne / cfg::maxIonsPerPrimary);

        const size_t stride = 1;  // track all ions, not just a subset

        double birthDistSum = 0.;
        int nBirth = 0;
        a_ni = 0;

        std::cout << "event " << ev << ", primary " << primaryIndex
                  << ": gain " << ne << ", duration " << a_duration
                  << " ns, collected " << a_nCollected
                  << ", nearest wire " << a_nearestWire
                  << ", distance = " << a_wireDist
                  << "\n";


        for (size_t i = 0; i < ne; i += stride) {
          double x0, y0, z0, t0, e0, x1, y1, z1, t1, e1;
          int st;
          aval.GetElectronEndpoint(i, x0, y0, z0, t0, e0, x1, y1, z1, t1, e1, st);

          int w;
          double d;
          NearestSenseWire(senseX, senseY, x0, y0, w, d);
          birthDistSum += d;
          ++nBirth;

          const double weight = static_cast<double>(stride);
          hBirthR.Fill(d, weight);
          hBirthT.Fill(t0, weight);

          if (!drift.DriftIon(x0, y0, z0, t0)) {
            ++failedIons;
            continue;
          }
          double xi, yi, zi, ti;
          int istatus;
          drift.GetEndPoint(xi, yi, zi, ti, istatus);

          i_event = ev;
          i_primary = primaryIndex;
          i_x = x0;
          i_y = y0;
          i_t = t0;
          i_wire = w;
          i_wireDist = d;
          i_driftTime = ti - t0;
          i_w = weight;
          tI.Fill();
          hIonDrift.Fill(i_driftTime, weight);
          ++a_ni;

          if (cfg::makeGif) {
            IonTrajectory traj;
            traj.w = weight;
            const size_t np = drift.GetNumberOfDriftLinePoints();
            traj.xs.reserve(np);
            traj.ys.reserve(np);
            traj.ts.reserve(np);
            for (size_t k = 0; k < np; ++k) {
              double xp, yp, zp, tp;
              drift.GetDriftLinePoint(k, xp, yp, zp, tp);
              traj.xs.push_back(xp);
              traj.ys.push_back(yp);
              traj.ts.push_back(tp);
            }
            ionTrajectories.push_back(std::move(traj));
            
          }
        }
        a_meanBirthDist = nBirth > 0 ? birthDistSum / nBirth : 0.;

        tA.Fill();
        hGain.Fill(a_gain);
        hDur.Fill(a_duration);

        totalElectrons += ne;
        totalIons += a_ni;
        if (a_hitLimit) ++nLimited;
        ++nPrimariesAll;
        ++primaryIndex;

        if (primaryIndex % 10 == 0) {
          std::cout << "event " << ev << ", primary " << primaryIndex
                    << ": gain " << ne << ", duration " << a_duration << " ns\n";
        }
      }
    }
  }

  // --- Summary ------------------------------------------------------------
  std::cout << "\n==== Summary ====\n"
            << "Primary electrons:      " << nPrimariesAll << "\n"
            << "Mean gain:              "
            << (nPrimariesAll ? double(totalElectrons) / nPrimariesAll : 0.) << "\n"
            << "Size-limit hits:        " << nLimited
            << "  (if non-zero, gains are biased low: raise limit or lower voltage)\n"
            << "Ions drifted:           " << totalIons << "\n"
            << "Failed DriftIon calls:  " << failedIons << "\n";

  outFile.cd();
  tA.Write();
  tI.Write();
  hGain.Write();
  hDur.Write();
  hBirthR.Write();
  hBirthT.Write();
  hIonDrift.Write();
  hPrimDrift.Write();
  hAvArrival.Write();
  hAvLife.Write();

  // --- Summary canvas ---------------------------------------------------
  if (!cfg::onlygain) {
  gStyle->SetOptStat(1110);
  TCanvas cSum("cSum", "Avalanche summary", 1200, 800);
  cSum.Divide(3, 3);
  cSum.cd(1);
  hGain.Draw();
  cSum.cd(2);
  hDur.Draw();
  cSum.cd(3);
  // gPad->SetLogy();
  hBirthR.Draw();
  cSum.cd(4);
  hBirthT.Draw();
  cSum.cd(5);
  hIonDrift.Draw();
  cSum.cd(6);
  hPrimDrift.Draw();
  cSum.cd(7);
  hAvArrival.Draw();
  cSum.cd(8);
  hAvLife.Draw();
  cSum.cd(9);
  {
    // Birth positions of the drifted ions around the sense wires
    tI.SetMarkerStyle(7);
    tI.SetMarkerColor(kRed + 1);
    tI.Draw("y:x>>hXY(200,-0.05, 0.05,200,-0.05,0.05)", "", "colz");
  }
  cSum.SaveAs((cfg::outDir + "/avalanche_summary.png").c_str());
}
  TCanvas cGain("cGain", "Gain distribution", 600, 600);
  TH1D* hGainRebinned = static_cast<TH1D*>(hGain.Rebin(10, "hGainRebinned"));
  hGainRebinned->SetTitle("Gain distribution;electrons per avalanche;entries");
  hGainRebinned->Draw();
  cGain.SaveAs((cfg::outDir + "/avalanche_gain.png").c_str());

  TCanvas cDur("cDur", "Avalanche duration", 600, 600);
  TH1D* hDurRebinned = static_cast<TH1D*>(hDur.Rebin(5, "hDurRebinned"));
  hDurRebinned->SetTitle("Avalanche duration;#Delta t [ns];entries");
  hDurRebinned->Draw();
  cDur.SaveAs((cfg::outDir + "/avalanche_duration.png").c_str());

  // --- Optional ion-field animation ----------------------------------------
  if (cfg::makeGif && !ionTrajectories.empty()) {
    // choose dt so the whole ion movement fits in ~gifFrames frames
    double tMax = 0.;
    for (const auto& tr : ionTrajectories) tMax = std::max(tMax, tr.ts.back());
    const double dt = std::max(1., tMax / cfg::gifFrames);
    std::cout << "Animation: tMax = " << tMax << " ns, dt = " << dt << " ns\n";

    std::vector<IonTrajectory> resampled;
    resampled.reserve(ionTrajectories.size());
    for (const auto& tr : ionTrajectories) resampled.push_back(Resample(tr, dt));
    ionTrajectories.clear();

    long kEnd = 0;
    for (const auto& tr : resampled)
      kEnd = std::max<long>(kEnd, tr.k0 + static_cast<long>(tr.xs.size()));

    const double xmin = -2.64, xmax = 2.64, ymin = -2.64, ymax = 2.64;
    const double qe = 1.602176634e-19, eps0 = 8.8541878128e-12;
    const double kcm = qe / (4. * M_PI * eps0) * 100.;  // V*cm for E in V/cm
    const double soft2 = 0.005 * 0.005;

    const std::string gifName = cfg::outDir + "/avalanche_ion_field.gif";
    gSystem->Unlink(gifName.c_str());
    gStyle->SetOptStat(0);
    gStyle->SetPalette(kViridis);

    TH2D hE("hE", "Ion field;x [cm];y [cm];|E| [V/cm]", cfg::nBins, xmin, xmax,
            cfg::nBins, ymin, ymax);
    // Colour scale: tune after a first run (many more ions than primaries only)
    const double eMin = 1.e-4, eMax = 1.e1;
    TCanvas cE("cE", "Ion field", 600, 600);
    cE.SetRightMargin(0.16);
    cE.SetLogz();
    bool haveFrame = false;
    const int delay = 10;

    TGraph gSense(senseX.size(), senseX.data(), senseY.data());
    gSense.SetMarkerStyle(25);
    gSense.SetMarkerColor(kWhite);
    TGraph gField(fieldX.size(), fieldX.data(), fieldY.data());
    gField.SetMarkerStyle(21);
    gField.SetMarkerColor(kWhite);

    for (long k = 0; k < kEnd; ++k) {
      std::vector<double> xs, ys, ws;
      for (const auto& tr : resampled) {
        const long idx = k - tr.k0;
        if (idx >= 0 && idx < static_cast<long>(tr.xs.size())) {
          xs.push_back(tr.xs[idx]);
          ys.push_back(tr.ys[idx]);
          ws.push_back(tr.w);
          // Break loop when last ion has left the box perimeter defined by xmin/xmax/ymin/ymax
          if (xs.back() < xmin || xs.back() > xmax || ys.back() < ymin || ys.back() > ymax) {
            xs.pop_back();
            ys.pop_back();
            ws.pop_back();
          }

        }
      }
      if (xs.empty()) continue;

      hE.Reset();
      for (int ix = 1; ix <= cfg::nBins; ++ix) {
        const double px = hE.GetXaxis()->GetBinCenter(ix);
        for (int iy = 1; iy <= cfg::nBins; ++iy) {
          const double py = hE.GetYaxis()->GetBinCenter(iy);
          if (px * px + py * py > cfg::rTube * cfg::rTube) continue;
          double Ex = 0., Ey = 0.;
          for (size_t i = 0; i < xs.size(); ++i) {
            const double dx = px - xs[i], dy = py - ys[i];
            const double r2 = dx * dx + dy * dy + soft2;
            const double inv = ws[i] / (r2 * std::sqrt(r2));
            Ex += dx * inv;
            Ey += dy * inv;
          }
          hE.SetBinContent(ix, iy, kcm * std::sqrt(Ex * Ex + Ey * Ey));
        }
      }
      // Break loop when last ion has left the box perimeter defined by xmin/xmax/ymin/ymax
      // auto abs_min_x = std::min_element(xs.begin(), xs.end(), [](double a, double b) { return std::abs(a) < std::abs(b); });
      // auto abs_max_x = std::max_element(xs.begin(), xs.end(), [](double a, double b) { return std::abs(a) < std::abs(b); });
      // auto abs_min_y = std::min_element(ys.begin(), ys.end(), [](double a, double b) { return std::abs(a) < std::abs(b); });
      // auto abs_max_y = std::max_element(ys.begin(), ys.end(), [](double a, double b) { return std::abs(a) < std::abs(b); });
      // if ((std::abs(*abs_min_x) > std::abs(xmin) && std::abs(*abs_max_x) > std::abs(xmax)) ||
      //     (std::abs(*abs_min_y) > std::abs(ymin) && std::abs(*abs_max_y) > std::abs(ymax))) {
      //   k = kEnd;
      //   break;
      // }

      TGraph gIons(xs.size(), xs.data(), ys.data());
      gIons.SetMarkerStyle(20);
      gIons.SetMarkerSize(0.5);
      gIons.SetMarkerColor(kRed);


      cE.Clear();
      hE.SetMinimum(eMin);
      hE.SetMaximum(eMax);
      hE.Draw("COLZ");
      gIons.Draw("P SAME");
      gSense.Draw("P SAME");
      gField.Draw("P SAME");
      TLatex lab;
      lab.SetTextSize(0.035);
      lab.SetTextColor(kRed);
      lab.DrawLatexNDC(0.15, 0.88, Form("t = %.0f ns", k * dt));
      lab.DrawLatexNDC(0.15, 0.83, Form("N_{macro} = %zu", xs.size()));
      cE.Update();
      cE.Print(Form("%s+%d", gifName.c_str(), delay));
      haveFrame = true;
    }
    if (haveFrame) {
      cE.Clear();
      cE.Print(Form("%s++", gifName.c_str()));  // finalise (loops forever)
    }
  }

  outFile.Close();
  std::cout << "Results written to " << cfg::outDir << "/avalanches.root\n";
  return 0;
}