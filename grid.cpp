#include "grid.h"

Grid::Grid(int x_size, int y_size): sq_x_size(x_size), sq_y_size(y_size)
{
    // заполняем поле рандомными весами
    int n = sq_x_size*sq_y_size;
    for(int i=0; i<n; i++)
        squares.push_back(rand()%56);
    sq_size = 20;
    doc = nullptr;
}

void Grid::fill_sq(Point sq, Color color){

}
void Grid::drawGrid(){
    Dimensions dimensions(100, 100);
    Document * doc = new Document("my_svg.svg", Layout(dimensions, Layout::TopLeft));
    int n = sq_x_size*sq_y_size;
    for(int i=0; i<n; i++){
        SqPos sq = {i/sq_x_size, i-sq_x_size*(i/sq_x_size)};
        *doc << Text(Point(sq_size*sq.x+1, sq_size*sq.y+3),
                     std::to_string(sq.x)+", "+
                             std::to_string(sq.y)+", "+
                             std::to_string(squares[i]),
                     Color::Black, Font(3, "Arial"));
        *doc << Rectangle(Point(sq_size*sq.x, sq_size*sq.y), sq_size,sq_size, Color::Transparent, Stroke(.5, Color::Blue));
    }
    doc->save();
    doc= nullptr;
}
void Grid::newDoc(std::string fileName){

}
void Grid::saveDoc(){

}