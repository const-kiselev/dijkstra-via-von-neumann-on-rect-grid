#include "dijkstra.h"

int main() {
    srand(time(NULL));
    Grid g(10,10);
    Dijkstra::search(g, SqPos(0,0), SqPos(5,5));
    return 0;
}