#include <iostream>
#include <vector>
#include <string>
#include "../include/build_layer_geom.h"



// ---- full layer geometry: build once ----

std::tuple<std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double>> build_layer_geometry(double rad_cell_in, double rad_cell_out, double pitch_rad, int nwires) {
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

return std::make_tuple(senseX, senseY, fieldX, fieldY);
}

