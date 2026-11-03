// gas.cc - Garfield++ basics, part 1: electron transport in a gas.
//
// Computes (with Magboltz) drift velocity etc. for He:C2H6 50:50, the gas
// used in the Belle II CDC. The result is saved to a gas file that
// drift_tube.C loads later, so you only pay the Magboltz cost once.

#include <fstream>
#include <iostream>

#include <TApplication.h>

#include "Garfield/MediumMagboltz.hh"
#include "Garfield/ViewMedium.hh"

using namespace Garfield;

int main(int argc, char* argv[]) {
  TApplication app("app", &argc, argv);

  const std::string gasFile = "../gas_files/He_50_C2H6_50.gas";
  const std::string outDir = "../plots/He_50_C2H6_50";  // output directory (created if missing)

  MediumMagboltz gas;
  gas.SetComposition("he", 50., "c2h6", 50.);  // percentages
  gas.SetTemperature(293.15);                  // K
  gas.SetPressure(760.);                       // Torr

  std::ifstream f(gasFile);
  if (f.good()) {
    std::cout << "Loading existing gas file " << gasFile << "\n";
    gas.LoadGasFile(gasFile);
  } else {
    std::cout << "Running Magboltz (takes a minute or few)...\n";
    // Field grid: 100 V/cm ... 100 kV/cm, 20 points, log spacing.
    gas.SetFieldGrid(100., 100000, 10, true);
    // Argument = number of collisions in units of 1e7 (more = smoother).
    gas.GenerateGasTable(3);
    gas.WriteGasFile(gasFile);
  }
  gas.PrintGas();

  // Ask for one number: electron drift velocity at E = 1 kV/cm, B = 0.
  // Units: E in V/cm, B in Tesla, velocity in cm/ns.
  double vx = 0, vy = 0, vz = 0;
  if (gas.ElectronVelocity(1000., 0., 0., 0., 0., 0., vx, vy, vz)) {
    std::cout << "Drift velocity at 1 kV/cm: " << vx * 1.e4 << " um/ns\n";
  }

  // Same field with a 1.5 T magnetic field along z (Belle II solenoid):
  // the drift direction rotates (Lorentz angle) and the speed changes.
  if (gas.ElectronVelocity(1000., 0., 0., 0., 0., 1.5, vx, vy, vz)) {
    std::cout << "With Bz = 1.5 T: vx = " << vx * 1.e4 << ", vy = "
              << vy * 1.e4 << " um/ns\n";
  }

  // Plot drift velocity vs. E.
  ViewMedium view;
  view.SetMedium(&gas);
  view.PlotElectronVelocity('e');

  app.Run(true);
  return 0;
}
