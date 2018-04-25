//
// Created by const on 26/04/2018.
//

#include "dijkstra.h"

void Dijkstra::search
        (Grid graph,
         Point start,
         Point goal,
         std::map<Point, Point>& came_from,
         std::map<Point, int>& cost_so_far)
{
//    PriorityQueue frontier;
//    frontier.put(start, 0);
//
//    came_from[start] = start;
//    cost_so_far[start] = 0;
//
//    while (!frontier.empty()) {
//        Point current = frontier.get();
//        std::cout << "-----";current.print();
//        std::cout <<std::endl;
//
//        if (current == goal) {
//            break;
//        }
//
//        for (Hex* next : graph.neighbors(current)) {
//            int new_cost = cost_so_far[current] + graph.cost(next->hexCube());
//            if (cost_so_far.find(next->hexCube()) == cost_so_far.end()
//                || new_cost < cost_so_far[next->hexCube()]) {
//                cost_so_far[next->hexCube()] = new_cost;
//                came_from[next->hexCube()] = current;
//                frontier.put(next->hexCube(), new_cost);
//            }
//        }
//    }
}

std::vector<Point> Dijkstra::reconstruct_path(
        Point start, Point goal,
        std::map<Point, Point> came_from
) {
    std::vector<Point> path;
//    Point current = goal;
//    while (current != start) {
//        path.push_back(current);
//        current = came_from[current];
//    }
//    path.push_back(start); // optional
//    std::reverse(path.begin(), path.end());
    return path;
}