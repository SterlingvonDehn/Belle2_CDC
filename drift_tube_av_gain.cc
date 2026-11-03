#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <filesystem>

#include "TCanvas.h"
#include "TPad.h"
#include "TH1D.h"
#include "TGraphErrors.h"
#include "TMultiGraph.h"
#include "TLegend.h"
#include "TEllipse.h"
#include "TH2D.h"


#include "Garfield/AvalancheMicroscopic.hh"
#include "Garfield/ComponentAnalyticField.hh"
#include "Garfield/DriftLineRKF.hh"
#include "Garfield/MediumMagboltz.hh"
#include "Garfield/Sensor.hh"
#include "Garfield/TrackHeed.hh"

using namespace Garfield;

const std::string gasFile = "../gas_files/He_90_C4H10_10.gas";
const std::string outDir = "../plots/He_90_C4H10_10";  // output directory (created if missing)


const double rTube = 1.82;               // cm
const double senseDiameter = 30.e-4;       // cm
const double fieldDiameter = 126.e-4;      // cm
// const int vSense = 1400;               // V 
// const double pitch = 0.91;                // cmß

const double rad_cell_in = 16.8; //cm
const double rad_cell_out = 23.8; //cm
const int nSenseWires = 160;
const int nwires = 2*nSenseWires; // total number of wires in a cell (field + sense)
const int nlayers = 8;
const double pitch_rad = (rad_cell_out - rad_cell_in)/(2*nlayers-2); //cm

//for constant track position
const double nPrimaries = 100;              // number of primary electrons per track
// const double ymin = -pitch, ymax = pitch;
// const double dy = 2*pitch/nPrimaries;

std::vector <int> vSenseList = {700,800,900,1000,1100,1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000,2100,2200,2300,2400,2500}; // V

const double trackX = 0.25, trackY = 0.25;  
const std::string part_type = "muon";
const double part_mom = 1.e9;  // eV/c

const bool gen_plots = true;  // generate plots for each sense voltage

int main() {
    std::filesystem::create_directories(outDir + "/gains");

    // ---- gas: load once ----
    MediumMagboltz gas;
    if (!gas.LoadGasFile(gasFile)) { std::cerr << "Gas file failed\n"; return 1; }
    gas.SetMaxElectronEnergy(150);

    // ---- full layer geometry: build once ----
    std::vector<double> senseX, senseY, fieldX, fieldY;
    bool sense_lay = false, shift_lay = false;
    for (double rad = rad_cell_in - pitch_rad; rad <= rad_cell_out + pitch_rad; rad += pitch_rad) {
        double lay_pitch = 2 * M_PI * rad / nwires;
        int sense_index = shift_lay ? 1 : 0;
        for (int ix = 0; ix < nwires; ++ix) {
            double xcord = sin(ix * lay_pitch / rad) * rad;
            double ycord = cos(ix * lay_pitch / rad) * rad;
            if (sense_lay && sense_index % 2 == 0) { senseX.push_back(xcord); senseY.push_back(ycord); }
            else                                   { fieldX.push_back(xcord); fieldY.push_back(ycord); }
            sense_index++;
        }
        if (!sense_lay) sense_lay = true;
        else { shift_lay = !shift_lay; sense_lay = false; }
    }

    // ---- select one cell, positions relative to the sense wire: once ----
    const size_t sIdx = 3 * nSenseWires;          // a middle sense layer
    const double sx = senseX[sIdx], sy = senseY[sIdx];

    std::vector<std::pair<double, size_t>> dist2;
    for (size_t i = 0; i < fieldX.size(); ++i) {
        double dx = fieldX[i] - sx, dy = fieldY[i] - sy;
        dist2.emplace_back(dx*dx + dy*dy, i);
    }
    std::sort(dist2.begin(), dist2.end());

    const size_t nFieldPerCell = 8;
    std::vector<double> relX, relY;
    for (size_t k = 0; k < nFieldPerCell; ++k) {
        size_t i = dist2[k].second;
        relX.push_back(fieldX[i] - sx);
        relY.push_back(fieldY[i] - sy);
        std::cout << "f" << k << " rel pos (" << relX.back() << ", " << relY.back() << ")\n";
    }

    std::vector<double> mean_gain_list, mean_gain_error_list;
    std::vector<double> mean_drift_time_list, mean_drift_time_error_list, vSenseD;

    // ---- voltage scan ----
    for (const auto& vSense : vSenseList) {
        std::cout << "Running simulation for sense voltage: " << vSense << " V\n";

        ComponentAnalyticField cmp;
        cmp.SetMedium(&gas);
        cmp.AddWire(0., 0., senseDiameter, vSense, "s0");
        for (size_t i = 0; i < relX.size(); ++i)
            cmp.AddWire(relX[i], relY[i], fieldDiameter, 0., "f" + std::to_string(i));
        cmp.AddTube(rTube, 0., 0, "tube");

        Sensor sensor;
        sensor.AddComponent(&cmp);
        AvalancheMicroscopic aval;
        aval.SetSensor(&sensor);
        DriftLineRKF drift(&sensor);

        const std::string v = std::to_string(vSense);
        TH1D hGain(("hGain" + v).c_str(), "Avalanche gain;gain;counts", 15, 0, 0);
        TH1D tDriftTime(("tDrift" + v).c_str(), "Drift time;drift time [ns];counts", 100, 0, 0);

        const double x0 = trackX, y0 = trackY;      // fixed start point
        bool over_gain_limit = false;

        for (int j = 0; j < nPrimaries; ++j) {
            aval.AvalancheElectron(x0, y0, 0, 0, 0.1, 0., 0., 0.);
            double gain = aval.GetNumberOfElectronEndpoints();
            hGain.Fill(gain);

            drift.DriftElectron(x0, y0, 0, 0);
            double xend, yend, zend, tend; int status;
            drift.GetEndPoint(xend, yend, zend, tend, status);
            tDriftTime.Fill(tend);

            if (gain > 1e6) { over_gain_limit = true; break; }
        }

        if (gen_plots) {
            TCanvas cGain("cGain", "Avalanche Gain", 800, 600);
            hGain.Draw();
            cGain.SaveAs((outDir + "/gains/avalanche_gain_" + v + ".png").c_str());
            TCanvas cDT("cDT", "Drift Time", 800, 600);
            tDriftTime.Draw();
            cDT.SaveAs((outDir + "/gains/drift_time_distribution_" + v + ".png").c_str());
        }

        mean_gain_list.push_back(hGain.GetMean());
        mean_gain_error_list.push_back(hGain.GetMeanError());
        mean_drift_time_list.push_back(tDriftTime.GetMean());
        mean_drift_time_error_list.push_back(tDriftTime.GetMeanError());
        vSenseD.push_back(vSense);

        std::cout << "V=" << vSense << "  gain=" << hGain.GetMean() << " ± " << hGain.GetMeanError()
                  << "  drift=" << tDriftTime.GetMean() << " ± " << tDriftTime.GetMeanError() << " ns\n";

        if (over_gain_limit || hGain.GetMean() > 1e6) break;
    }

    TCanvas* cGeom = new TCanvas("cGeom", "Cell Geometry", 900, 900);
    cGeom->SetGrid();

    // Empty frame with equal x/y scaling, so the tube is drawn as a circle
    const double lim = rTube * 1.1;
    TH2D* frame = new TH2D("frame", "Cell geometry;X [cm];Y [cm]",
                        10, -lim, lim, 10, -lim, lim);
    frame->SetStats(false);
    frame->Draw();

    // Tube wall
    TEllipse* tube = new TEllipse(0., 0., rTube, rTube);
    tube->SetFillStyle(0);
    tube->SetLineColor(kBlack);
    tube->SetLineWidth(2);
    tube->Draw("same");

    // Sense wire (at the origin)
    double sxp[1] = {0.}, syp[1] = {0.};
    TGraph* gSense = new TGraph(1, sxp, syp);
    gSense->SetMarkerStyle(20);
    gSense->SetMarkerSize(1.8);
    gSense->SetMarkerColor(kRed);
    gSense->Draw("P same");

    // Field wires
    TGraph* gField = new TGraph(relX.size(), relX.data(), relY.data());
    gField->SetMarkerStyle(20);
    gField->SetMarkerSize(1.3);
    gField->SetMarkerColor(kBlue);
    gField->Draw("P same");

    // Electron start position
    double ex[1] = {trackX}, ey[1] = {trackY};
    TGraph* gStart = new TGraph(1, ex, ey);
    gStart->SetMarkerStyle(29);          // star
    gStart->SetMarkerSize(2.5);
    gStart->SetMarkerColor(kGreen + 2);
    gStart->Draw("P same");

    TLegend* leg = new TLegend(0.15, 0.78, 0.40, 0.89);
    leg->AddEntry(gSense, "Sense wire", "p");
    leg->AddEntry(gField, "Field wires", "p");
    leg->AddEntry(gStart, "Electron start", "p");
    leg->AddEntry(tube,   "Tube", "l");
    leg->Draw();

    cGeom->SaveAs((outDir + "/cell_geometry.png").c_str());

    TGraphErrors* gr = new TGraphErrors(vSenseD.size(), vSenseD.data(), mean_gain_list.data(), nullptr, mean_gain_error_list.data());

    TCanvas *cMeanGain = new TCanvas("cMeanGain", "Mean Avalanche Gain vs Sense Voltage", 800, 600);
    gr->SetTitle("Mean Avalanche Gain vs Sense Voltage;Sense Voltage (V);Mean Gain");
    gr->Draw("AP");
    gr->SetMarkerStyle(21);
    gr->SetMarkerSize(1);
    cMeanGain->SetLogy();
    cMeanGain->SaveAs((outDir + "/mean_avalanche_gain_vs_voltage.png").c_str());

    TGraphErrors* grDriftTime = new TGraphErrors(vSenseD.size(), vSenseD.data(), mean_drift_time_list.data(), nullptr, mean_drift_time_error_list.data());
    TCanvas *cMeanDriftTime = new TCanvas("cMeanDriftTime", "Mean Drift Time vs Sense Voltage", 800, 600);
    grDriftTime->SetTitle("Mean Drift Time vs Sense Voltage;Sense Voltage (V);Mean Drift Time (ns)");
    grDriftTime->Draw("AP");
    grDriftTime->SetMarkerStyle(21);
    grDriftTime->SetMarkerSize(1);
    cMeanDriftTime->SaveAs((outDir + "/mean_drift_time_vs_voltage.png").c_str());

    return 0;
}






























// int main(int argc, char* argv[]) {

//     //make directory if it doesn't exist
//     std::filesystem::create_directories(outDir + "/gains");

//     std::vector<double> mean_gain_list;
//     std::vector<double> mean_gain_error_list;
//     std::vector<double> mean_drift_time_list;
//     std::vector<double> mean_drift_time_error_list;
//     std::vector<double> vSenseD;

//     bool over_gain_limit = false;

//     std::vector<double> senseX, senseY, fieldX, fieldY;
//     for (const auto& vSense : vSenseList) {
//         std::cout << "Running simulation for sense voltage: " << vSense << " V\n";

//         // Load the gas mixture from a file
//         MediumMagboltz gas;
//         gas.LoadGasFile(gasFile);
//         gas.SetMaxElectronEnergy(150);  // eV

//         // Create the analytic field component and add wires
//         ComponentAnalyticField cmp;
//         cmp.SetMedium(&gas);
        
//         // FULL LAYER WIRE GEOMETRY
//         bool sense_lay = false;
//         bool shift_lay = false;
//         for (double rad = rad_cell_in - pitch_rad; rad <= rad_cell_out + pitch_rad; rad += pitch_rad) {
//             double lay_pitch = 2 * M_PI * rad / nwires;
//             //add wires in a circular pattern
//             int sense_index;
//             if (shift_lay) {
//                 sense_index = 1;
//                 }
//             else {
//                 sense_index = 0;
//             }

//             for (int ix = 0; ix < nwires; ++ix) {
//                 double xcord = sin(ix*lay_pitch/rad)*rad;
//                 double ycord = cos(ix*lay_pitch/rad)*rad;
//                 if (sense_lay && sense_index % 2 == 0) {
//                     // cmp.AddWire(xcord, ycord, senseDiameter, vSense, "s0");
//                     senseX.push_back(xcord);
//                     senseY.push_back(ycord);
//                 } else {
//                     // cmp.AddWire(xcord, ycord, fieldDiameter, 0, "f" + std::to_string(ix));
//                     fieldX.push_back(xcord);
//                     fieldY.push_back(ycord);
//                 }
//                 sense_index++;
//             }

//             if (sense_lay == false) {
//                 sense_lay = true;
//             } else {
//                 if (shift_lay == false) {
//                     shift_lay = true;
//                 } else {
//                     shift_lay = false;
//                 }
//                 sense_lay = false;
//             }
//         }

//         // Only add wires for 1 cell: one sense wire + its nearest field wires
//         std::vector<double> senseX_cell, senseY_cell;
//         std::vector<double> fieldX_cell, fieldY_cell;

//         // Choose the sense wire for the cell (here: first one; pick any index you like)
//         const size_t sIdx = 0;
//         const double sx = senseX[sIdx];
//         const double sy = senseY[sIdx];

//         senseX_cell.push_back(sx);
//         senseY_cell.push_back(sy);

//         // Squared distance from the sense wire to every field wire
//         std::vector<std::pair<double, size_t>> dist2; // (r^2, index into fieldX/fieldY)
//         dist2.reserve(fieldX.size());
//         for (size_t i = 0; i < fieldX.size(); ++i) {
//             double dx = fieldX[i] - sx;
//             double dy = fieldY[i] - sy;
//             dist2.emplace_back(dx*dx + dy*dy, i);
//         }

//         // Sort by distance and keep the nearest N field wires
//         const size_t nFieldPerCell = 8;   // 8 for a square-ish cell, 6 for hexagonal
//         std::sort(dist2.begin(), dist2.end());   // needs <algorithm>

//         for (size_t k = 0; k < nFieldPerCell && k < dist2.size(); ++k) {
//             size_t i = dist2[k].second;
//             fieldX_cell.push_back(fieldX[i]);
//             fieldY_cell.push_back(fieldY[i]);
//         }

//         cmp.AddWire(senseX_cell[0] - senseX_cell[0], senseY_cell[0]-senseY_cell[0], senseDiameter, vSense, "s" + std::to_string(0));

//         for (size_t i = 0; i < fieldX_cell.size(); ++i) {
//             cmp.AddWire(fieldX_cell[i] - senseX_cell[0], fieldY_cell[i] - senseY_cell[0], fieldDiameter, 0, "f" + std::to_string(i));
//         }

//         cmp.AddTube(rTube, 0, 0, "tube");

//         // Create the sensor and add the gas medium
//         Sensor sensor;
//         sensor.AddComponent(&cmp);

//         AvalancheMicroscopic aval;
//         aval.SetSensor(&sensor);

//         DriftLineRKF drift(&sensor);


//         // track.NewTrack(trackX, trackY, 0., 0., 0., 1., 0.);  // x, y, z, t, dx, dy, dz

//         TH1D hGain("hGain", "Avalanche gain;gain;counts", 15, 0, 0);
//         TH1D tDriftTime("tDriftTime", "Drift time distribution;drift time [ns];counts", 100, 0, 0);

//         double xc, yc, zc, tc, ec, extra;
//         int nc;
//         double xe = trackX;
//         double ye = trackY;

//         std::cout << "Primary electron starting position: (" << xe << ", " << ye << ")\n";
//         std::cout << "Sense wire position: (" << senseX_cell[0] << ", " << senseY_cell[0] << ")\n";
//         std::cout << "tube center position: (" << 0 << ", " << 0 << ")\n";
//         // while (track.GetCluster(xc, yc, zc, tc, nc, ec, extra)) {
//         for (int j = 0; j < nPrimaries; ++j) {
//             double zc, tc;
//             int nc;
//             // double xe, ye, ze, te, ee, dxe, dye, dze;
//             // track.GetElectron(j, xe, ye, ze, te, ee, dxe, dye, dze);

//             // only track electrons which are produced inside the central cell (nearest sense wire is s0)
//             // if ((abs(xe) > pitch) || (abs(ye) > pitch)) {
//             //     // std::cout << "Skipping primary electron at (" << xe << ", " << ye << ") - outside the central cell\n";
//             //     continue;
//             // }
//             aval.AvalancheElectron(xe, ye, 0, 0, 0.1, 0., 0., 0.);
//             drift.DriftElectron(xe, ye, 0, 0);

//             drift.GetEndPoint(xe, ye, zc, tc, nc);
//             double driftTime = tc;  // ns
//             tDriftTime.Fill(driftTime);

//             double gain = aval.GetNumberOfElectronEndpoints();
//             hGain.Fill(gain);

//             if (gain > 1e6) {
//                 std::cout << "Gain exceeded 1e6 for sense voltage " << vSense << " V. Stopping simulation for this voltage.\n";
//                 over_gain_limit = true;
//                 break;
//             }

//         }

//         if (over_gain_limit) {
//             break;
//         }

//         if (gen_plots) {
//             TCanvas* cGain = new TCanvas("cGain", "Avalanche Gain", 800, 600);
//             hGain.Draw();
//             cGain->SaveAs((outDir + "/gains" + "/avalanche_gain_" + std::to_string(vSense) + ".png").c_str());

//             TCanvas* cDriftTime = new TCanvas("cDriftTime", "Drift Time Distribution", 800, 600);
//             tDriftTime.Draw();
//             cDriftTime->SaveAs((outDir + "/gains" + "/drift_time_distribution_" + std::to_string(vSense) + ".png").c_str());
//         }

//         // Calculate mean gain and its error
//         double meanGain = hGain.GetMean();
//         double meanGainError = hGain.GetMeanError();
//         mean_gain_list.push_back(meanGain);
//         mean_gain_error_list.push_back(meanGainError);
//         vSenseD.push_back(static_cast<double>(vSense));

//         // Calculate mean drift time and its error
//         double meanDriftTime = tDriftTime.GetMean();
//         double meanDriftTimeError = tDriftTime.GetMeanError();
//         mean_drift_time_list.push_back(meanDriftTime);
//         mean_drift_time_error_list.push_back(meanDriftTimeError);

//         std::cout << "Sense Voltage: " << vSense << " V, Mean Gain: " << meanGain << " ± " << meanGainError
//                   << ", Mean Drift Time: " << meanDriftTime << " ± " << meanDriftTimeError << " ns\n";
//         if (meanGain > 1e6) {
//             std::cout << "Simulation stopped for sense voltage " << vSense << " V due to gain limit.\n";
//             break;
//         }

//     }