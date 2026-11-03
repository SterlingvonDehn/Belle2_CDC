cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(GarfieldBasics)

# Needs the Garfield++ environment: source .../install/share/Garfield/setupGarfield.sh
# If cmake cannot find it, add -DCMAKE_PREFIX_PATH=$GARFIELD_HOME
find_package(Garfield REQUIRED)
find_package(ROOT REQUIRED COMPONENTS Tree)

# Shared helper library (no main())
add_library(build_layer_geom src/build_layer_geom.cc)
target_include_directories(build_layer_geom PUBLIC include)

add_executable(gas src/gas.cc)
target_link_libraries(gas Garfield::Garfield)

add_executable(drift_tube_cell src/drift_tube_cell.cc)
target_link_libraries(drift_tube_cell Garfield::Garfield)

add_executable(drift_tube_cluster src/drift_tube_cluster.cc)
target_link_libraries(drift_tube_cluster Garfield::Garfield)

add_executable(drift_tube_avalanche src/drift_tube_avalanche.cc)
target_link_libraries(drift_tube_avalanche Garfield::Garfield ROOT::Tree)

add_executable(drift_tube_av_gain src/drift_tube_av_gain.cc)
target_link_libraries(drift_tube_av_gain Garfield::Garfield ROOT::Tree)

add_executable(wire_sag src/wire_sag.cc)
target_link_libraries(wire_sag PRIVATE Garfield::Garfield ROOT::Tree build_layer_geom)
