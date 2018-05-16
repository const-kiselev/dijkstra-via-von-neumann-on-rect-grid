#include "grid.h"

Grid::Grid(int x_size, int y_size): sq_x_size(x_size), sq_y_size(y_size)
{
    // заполняем поле рандомными весами
    int n = sq_x_size*sq_y_size;
    for(int i=0; i<n; i++)
        squares.push_back(rand()%506);
    sq_size = 1000.0/max(sq_x_size, sq_y_size);
}

void Grid::drawGridViaSVG(string fileName,
                          map<SqPos, int>* cost_so_far ,map<SqPos, int> path)
{

    Document * doc = new Document(fileName+".svg", Layout(Dimensions(1000,1000), Layout::TopLeft));
    int n = sq_x_size*sq_y_size;
    for(int i=0; i<n; i++){
        SqPos sq = {i/sq_x_size, i-sq_x_size*(i/sq_x_size)};
        Color color(255,255,255);
        if(cost_so_far)
            if(cost_so_far->find(sq) != cost_so_far->end())
                color = Color(170,50,50);


        if(!path.empty())
            if(path.find(sq) != path.end())
                color = Color(100,100,100);

        *doc << Rectangle(Point(sq_size*sq.x, sq_size*sq.y), sq_size,sq_size, color, Stroke(.5, Color::Blue));
        *doc << Text(Point(sq_size*sq.x+1, sq_size*sq.y+3),
                     std::to_string(sq.x)+", "+
                     std::to_string(sq.y)+", "+
                     std::to_string(squares[i]),
                     Color::Black, Font(sq_size/5, "Arial"));
    }
    doc->save();
}

vector<SqElem> Grid::neighbors(SqPos pos) {
    vector<SqElem> res;
    if(pos.y !=sq_y_size-1)
        res.push_back(SqElem(pos.x, pos.y+1, squares[index(pos.x, pos.y+1)]));
    if(pos.y != 0)
        res.push_back(SqElem(pos.x, pos.y-1, squares[index(pos.x, pos.y-1)]));
    if(pos.x != 0)
        res.push_back(SqElem(pos.x-1, pos.y, squares[index(pos.x-1, pos.y)]));
    if(pos.x !=sq_x_size-1)
        res.push_back(SqElem(pos.x+1, pos.y, squares[index(pos.x+1, pos.y)]));

    return res;
}
