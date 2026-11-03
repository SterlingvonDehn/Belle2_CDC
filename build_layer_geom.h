#pragma once
#include <tuple>
#include <vector>

std::tuple<std::vector<double>, std::vector<double>, std::vector<double>, std::vector<double>> build_layer_geometry(double rad_cell_in, double rad_cell_out, double pitch_rad, int nwires);