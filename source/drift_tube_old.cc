// drift_tube.cc - Garfield++ basics, part 2: a single-wire drift tube.
//
// A round tube (1 cm radius, grounded) with a 30 um sense wire at its centre.
// A 1 GeV/c muon crosses the tube; Heed makes ionisation clusters, and each
// primary electron is drifted to the wire. We print how long the FIRST
// electron takes to arrive (this is what a drift chamber TDC measures) and
// draw the drift lines.
//
// Run gas.C first so that he_c2h6.gas exists.

#include <fstream>
#include <iostream>

#include <TApplication.h>
#include <TCanvas.h>

#include "Garfield/ComponentAnalyticField.hh"
#include "Garfield/DriftLineRKF.hh"
#include "Garfield/MediumMagboltz.hh"
#include "Garfield/Sensor.hh"
#include "Garfield/TrackHeed.hh"
#include "Garfield/ViewCell.hh"
#include "Garfield/ViewDrift.hh"

using namespace Garfield;

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

  // --- Geometry and field -------------------------------------------
  const double rTube = 1.0;        // cm
  const double wireDiameter = 30.e-4;  // cm (30 um)
  const double vWire = 2000.;      // V
  const double vField = 0.;      // V (tube grounded)

  ComponentAnalyticField cmp;
  cmp.SetMedium(&gas);
  cmp.AddWire(-0.5, 0.5, wireDiameter, vField, "s1");
  cmp.AddWire(0.5, 0.5, wireDiameter, vField, "s2");
  cmp.AddWire(0,0.5, wireDiameter, vField, "s3");
  cmp.AddWire(0.5, -0.5, wireDiameter, vField, "s4");
  cmp.AddWire(-0.5, -0.5, wireDiameter, vField, "s5");
  cmp.AddWire(0, -0.5, wireDiameter, vField, "s6");
  cmp.AddWire(0.5, 0, wireDiameter, vField, "s7");
  cmp.AddWire(-0.5, 0, wireDiameter, vField, "s8");

  cmp.AddWire(0, 0, wireDiameter, vWire, "s9");


  cmp.AddTube(rTube, 0., 0, "tube");  // radius, voltage, nEdges=0 -> round

  Sensor sensor;
  sensor.AddComponent(&cmp);

  // --- Plotting -------------------------------------------------------
  TCanvas* canvas = new TCanvas("c", "Drift tube", 700, 700);
  ViewCell cellView;
  cellView.SetCanvas(canvas);
  cellView.SetComponent(&cmp);

  ViewDrift driftView;
  driftView.SetCanvas(canvas);

  // --- Particle track (Heed) and electron drift ------------------------
  TrackHeed track(&sensor);
  track.SetParticle("muon");
  track.SetMomentum(1.e9);  // eV/c
  track.EnablePlotting(&driftView);

  DriftLineRKF drift(&sensor);
  drift.EnablePlotting(&driftView);

  // Muon travelling in +y, passing 0.4 cm to the side of the wire.
  // Arguments: x0, y0, z0, t0, dx, dy, dz.
  track.NewTrack(0.4, -0.9, 0., 0., 0., 1., 0.);

  double xc, yc, zc, tc, ec, extra;
  int nc;
  int nClusters = 0, nElectrons = 0;
  double firstArrival = 1.e9;  // ns

  while (track.GetCluster(xc, yc, zc, tc, nc, ec, extra)) {
    ++nClusters;
    for (int j = 0; j < nc; ++j) {
      double xe, ye, ze, te, ee, dxe, dye, dze;
      track.GetElectron(j, xe, ye, ze, te, ee, dxe, dye, dze);
      ++nElectrons;

      drift.DriftElectron(xe, ye, ze, te);
      double xf, yf, zf, tf;
      int status;
      drift.GetEndPoint(xf, yf, zf, tf, status);
      if (tf - te < firstArrival) firstArrival = tf - te;
    }
  }

  std::cout << "Clusters: " << nClusters << ", primary electrons: "
            << nElectrons << "\n"
            << "Drift time of first electron: " << firstArrival << " ns\n";

  // --- Draw -------------------------------------------------------------
  cellView.Plot2d();
  constexpr bool twod = true;
  constexpr bool drawaxis = false;
  driftView.Plot(twod, drawaxis);
  canvas->Update();

  app.Run(true);
  return 0;
}
