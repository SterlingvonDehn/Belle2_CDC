#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "../include/build_layer_geom.h"

#include "TCanvas.h"
#include "TGraph.h"
#include "TEllipse.h"
#include "TH2D.h"
#include "TLegend.h"

#include "Garfield/ComponentAnalyticField.hh"


const double rTube = 10.0; // cm
const double rad_cell_in = 16.8; //cm
const double rad_cell_out = 23.8; //cm
const int nSenseWires = 160;
const int nwires = 2*nSenseWires; // total number of wires in a cell (field + sense)
const int nlayers = 8;
const double pitch_rad = (rad_cell_out - rad_cell_in)/(2*nlayers-2); //cm

const double senseDiameter = 30.e-4;       // cm
const double fieldDiameter = 126.e-4;      // cm
const double senseDense = 19.3; // g/cm^3
const double fieldDense = 2.70; // g/cm^3
const double senseTens = 50; // N
const double fieldTens = 80; // N
const double sense_volt = 2400; // V
const double field_volt = 0; // V

const double wireLength = 240; // cm

const bool allwires = true; // if false, only the 4-3-4 block is used

using namespace Garfield;

int main() {
    std::string outDir = "../plots";  // output directory (created if missing)

    auto [senseX, senseY, fieldX, fieldY] = build_layer_geometry(rad_cell_in, rad_cell_out, pitch_rad, nwires);

    const size_t nTotalLayers = senseX.size() / nSenseWires;

    
    std::vector<double> relSX, relSY, relFX, relFY; // relative positions of selected wires
    if (!allwires) {

    // ---------------- select the 4-3-4 block ----------------
    // assumes senseX/senseY are stored layer by layer, nSenseWires per layer
    const size_t sIdx = 3 * nSenseWires;   // first wire of a middle layer
    if (sIdx >= senseX.size()) {
        std::cerr << "sIdx out of range\n";
        return 1;
    }
    const int    centralLayer = static_cast<int>(sIdx / nSenseWires);
    const double sx = senseX[sIdx], sy = senseY[sIdx];

    // indices of the n wires in [first,last) closest to (x0,y0)
    auto nearest = [](const std::vector<double>& xs, const std::vector<double>& ys,
                      double x0, double y0, size_t first, size_t last, size_t n) {
        std::vector<std::pair<double, size_t>> d;
        for (size_t i = first; i < last; ++i) {
            const double dx = xs[i] - x0, dy = ys[i] - y0;
            d.emplace_back(dx * dx + dy * dy, i);
        }
        std::sort(d.begin(), d.end());
        std::vector<size_t> out;
        for (size_t k = 0; k < std::min(n, d.size()); ++k) out.push_back(d[k].second);
        return out;
    };

    struct LayerSel { int layerOffset; size_t nCells; };
    const std::vector<LayerSel> layout = { {+2, 9}, {+1, 7}, {0, 9}, {-1, 7}, {-2, 9} };

    std::set<size_t> senseSet;
    for (const auto& ls : layout) {
        const int layer = centralLayer + ls.layerOffset;
        if (layer < 0 || layer >= static_cast<int>(nTotalLayers)) {
            std::cerr << "Layer " << layer << " does not exist, skipping\n";
            continue;
        }
        const size_t first = static_cast<size_t>(layer) * nSenseWires;
        for (size_t i : nearest(senseX, senseY, sx, sy, first, first + nSenseWires, ls.nCells))
            senseSet.insert(i);
    }

    // central wire first so it is iw = 0
    std::vector<size_t> cellSense = {sIdx};
    for (size_t s : senseSet) if (s != sIdx) cellSense.push_back(s);

    // field wires: nearest few around every selected sense wire (set removes shared ones)
    std::set<size_t> fieldSet;
    const size_t nFieldPerCell = 8;
    for (size_t s : cellSense)
        for (size_t i : nearest(fieldX, fieldY, senseX[s], senseY[s], 0, fieldX.size(), nFieldPerCell))
            fieldSet.insert(i);

    // positions relative to the central sense wire
    for (size_t s : cellSense) {
        relSX.push_back(senseX[s] - sx);
        relSY.push_back(senseY[s] - sy);
    }
    for (size_t i : fieldSet) {
        relFX.push_back(fieldX[i] - sx);
        relFY.push_back(fieldY[i] - sy);
    }
    std::cout << "Selected block: " << relSX.size() << " sense wires, "
              << relFX.size() << " field wires\n";
    for (size_t i = 0; i < relSX.size(); ++i)
        std::cout << "  s" << i << " (" << relSX[i] << ", " << relSY[i] << ")\n";


    std::cout << relSX.size() << " sense wires, " << relFX.size() << " field wires\n";

    }

    else {
        std::cout << "Using all wires\n";
        relSX = senseX;
        relSY = senseY;
        relFX = fieldX;
        relFY = fieldY;
    }

    ComponentAnalyticField cmp;
    cmp.SetGravity(0, -1,0); // m/s^2

    for (size_t i = 0; i < relSX.size(); ++i) {
        cmp.AddWire(relSX[i], relSY[i], senseDiameter, sense_volt, "s" + std::to_string(i), wireLength, senseTens, senseDense);
    }

    for (size_t j = 0; j < relFX.size(); ++j) {
        cmp.AddWire(relFX[j], relFY[j], fieldDiameter, field_volt, "f" + std::to_string(j), wireLength, fieldTens, fieldDense);
    }

    if (allwires) {
        cmp.AddTube(rad_cell_out + 2*pitch_rad, 0, 0, "tube");
    }

    else {
        // add a tube only around the selected block
        cmp.AddTube(rTube, 0, 0, "tube");
    }

    //all wires:
    std::vector<double> wire_x, wire_y;
    for (size_t i = 0; i < relSX.size(); ++i) {
        wire_x.push_back(relSX[i]);
        wire_y.push_back(relSY[i]);
    }
    for (size_t i = 0; i < relFX.size(); ++i) {
        wire_x.push_back(relFX[i]);
        wire_y.push_back(relFY[i]);
    }

    // calculate the sag for all wires

    std::vector<double> csag, xsag, ysag;
    for (size_t iw = 0; iw < wire_x.size(); ++iw) {
        double XWire = wire_x[iw];
        double YWire = wire_y[iw];

        std::vector<double> csag_i, xsag_i, ysag_i;
        double stretch_i = 0;
        cmp.WireDisplacement(iw,false, csag_i, xsag_i, ysag_i,stretch_i);
        for (size_t i = 0; i < csag_i.size(); ++i) {
            csag.push_back(csag_i[i]);
            xsag.push_back(xsag_i[i]+XWire);
            ysag.push_back(ysag_i[i]+YWire);
        }
    }

    TCanvas* cGeom = new TCanvas("cGeom", "Cell Geometry", 1200, 1200);

    TGraph* gSense = new TGraph(relSX.size(), relSX.data(), relSY.data());
    gSense->SetMarkerStyle(21);
    gSense->SetMarkerSize(.5);
    gSense->SetMarkerColor(kRed);
    gSense->SetTitle("Cell Geometry;X [cm];Y [cm]");
    gSense->GetXaxis()->SetLimits(-4,4);
    gSense->GetYaxis()->SetRangeUser(-4,4);
    gSense->Draw("AP");

    TGraph* gField = new TGraph(relFX.size(), relFX.data(), relFY.data());
    gField->SetMarkerStyle(20);
    gField->SetMarkerSize(0.5);
    gField->SetMarkerColor(kBlue);
    gField->Draw("P same");  

    TGraph* gSag = new TGraph(xsag.size(), xsag.data(), ysag.data());
    gSag->SetMarkerStyle(5);
    gSag->SetMarkerSize(1);
    gSag->SetMarkerColor(kBlack);
    gSag->Draw("P same");

    cGeom->SaveAs((outDir + "/cell_geometry.png").c_str());

    return 0;
}