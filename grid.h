#ifndef GRID_H
#define GRID_H

#include <iostream>
#include "simple_svg_1.0.0_mod.hpp"
#include <map>
#include <algorithm>
//#include <vector>
#include <array>
#include <cmath>
#include <queue>

using namespace svg;
using namespace std;

// структура для описания позиции квадрата
// относительно левого верхнего угла
typedef struct SqPos {
    int x,y;
    SqPos(){}
    SqPos(int inX, int inY):x(inX), y(inY){}

    const bool operator == (const SqPos a) const
    {return ((this->x == a.x) &&  (this->y == a.y));}
    const bool operator != (const SqPos a)const
    {return !(*this == a);}
    const bool operator < (const SqPos a)const
    {return std::tie(a.x, a.y) < std::tie(this->x, this->y);}
};

// структура для описания квадрата (позиция [x,y] и вес w)
typedef struct SqElem{
    int x,y,w;
    SqElem(int inX, int inY, int inW):
            x(inX), y(inY), w(inW){}
};

class Grid {
    int sq_x_size; // кол-во квадратов по горизонтали
    int sq_y_size; // кол-во квадратов по вертикали
    float sq_size; // размер квадрата для отрисовки
    std::vector<int> squares; // вектор с весами
    double width;
    double height;
    int index(int x, int y){return x*sq_x_size+y;}

public:
    Grid(int x_size, int y_size);
    ~Grid(){};

    void drawGridViaSVG(string fileName,
                        map<SqPos, int>* cost_so_far = nullptr,
                        map<SqPos, int> path = {});
    vector<SqElem> neighbors(SqPos pos);

    SqPos getSize(){return SqPos(sq_x_size, sq_y_size);}
};


#endif
