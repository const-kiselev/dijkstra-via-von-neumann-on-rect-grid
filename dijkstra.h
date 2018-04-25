#ifndef DIJKSTRA_VIA_VON_NEUMANN_ON_RECT_GRID_DIJKSTRA_H
#define DIJKSTRA_VIA_VON_NEUMANN_ON_RECT_GRID_DIJKSTRA_H

#include "grid.h"

class Dijkstra {
    struct PriorityQueue {
//        typedef std::pair<HexData, HexCube> PQElement;
//        std::priority_queue<PQElement, std::vector<PQElement>,
//                std::greater<PQElement>> elements;
//
//        inline bool empty() const {
//            return elements.empty();
//        }
//
//        inline void put(HexCube item, HexData priority) {
//            elements.emplace(priority, item);
//        }
//
//        HexCube get() {
//            HexCube best_item = elements.top().second;
//            elements.pop();
//            return best_item;
//        }
    };
public:
    void search
            (Grid graph,
             Point start,
             Point goal,
             std::map<Point, Point>& came_from,
             std::map<Point, int>& cost_so_far);

    std::vector<Point> reconstruct_path(
            Point start, Point goal,
            std::map<Point, Point> came_from
    );
};


#endif //DIJKSTRA_VIA_VON_NEUMANN_ON_RECT_GRID_DIJKSTRA_H
