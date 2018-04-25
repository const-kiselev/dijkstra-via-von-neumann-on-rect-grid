cmake_minimum_required(VERSION 3.8)
project(dijkstra_via_von_neumann_on_rect_grid)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp simple_svg_1.0.0_mod.hpp grid.cpp grid.h dijkstra.cpp dijkstra.h)
add_executable(dijkstra_via_von_neumann_on_rect_grid ${SOURCE_FILES})