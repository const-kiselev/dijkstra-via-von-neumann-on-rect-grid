#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "grid.h"

class Dijkstra {
public:
    void static search  (Grid& graph,
                         SqPos start,
                         SqPos goal
    );
    map<SqPos, int> static reconstruct_path(
            SqPos start, SqPos goal,
            map<SqPos, SqPos> came_from);
};


#endif
