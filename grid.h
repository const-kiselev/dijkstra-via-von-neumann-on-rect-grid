#ifndef DIJKSTRA_VIA_VON_NEUMANN_ON_RECT_GRID_GRID_H
#define DIJKSTRA_VIA_VON_NEUMANN_ON_RECT_GRID_GRID_H

#include <iostream>
#include "simple_svg_1.0.0_mod.hpp"
#include <map>
#include <algorithm>
//#include <vector>
#include <array>
#include <cmath>
#include <queue>

using namespace svg;


typedef struct {int x,y;} SqPos;
typedef struct {int x,y,w;} SqElem;

class Grid {
    int sq_x_size;
    int sq_y_size;
    int sq_size;
    std::vector<int> squares;
    double width;
    double height;
    Document *doc;

public:
    Grid(int x_size, int y_size);
    ~Grid(){};

    void fill_sq(Point sq, Color color);
    void drawGrid();
    void newDoc(std::string fileName);
    void saveDoc();
};


#endif //DIJKSTRA_VIA_VON_NEUMANN_ON_RECT_GRID_GRID_H
