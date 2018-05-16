#include "dijkstra.h"
#include "grid.h"

void Dijkstra::search(Grid& graph,
                             SqPos start,
                             SqPos goal)
{
    map<SqPos, SqPos> came_from;
    map<SqPos, int> cost_so_far;
    struct PriorityQueue {
        typedef std::pair<int, SqPos> PQElement;
        std::priority_queue<PQElement, std::vector<PQElement>,
                std::greater<PQElement>> elements;

        inline bool empty() const {
            return elements.empty();
        }

        inline void put(SqPos item, int priority) {
            elements.emplace(priority, item);
        }

        SqPos get() {
            SqPos best_item = elements.top().second;
            elements.pop();
            return best_item;
        }
    } frontier;
    int i=0;
    frontier.put(start, 0);

    came_from[start] = start;
    cost_so_far[start] = 0;

    while (!frontier.empty()) {
        SqPos current = frontier.get();

        if (current == goal || cost_so_far.find(goal) != cost_so_far.end()) {
            break;
        }
        graph.drawGridViaSVG(to_string(i++), &cost_so_far);
        for (SqElem next : graph.neighbors(current))
        {
            int new_cost = cost_so_far[current] + next.w;

            if (cost_so_far.find(SqPos(next.x, next.y)) == cost_so_far.end()
                || new_cost < cost_so_far[SqPos(next.x, next.y)])
            {
                cost_so_far[SqPos(next.x, next.y)] = new_cost;
                came_from[SqPos(next.x, next.y)] = current;
                frontier.put(SqPos(next.x, next.y), new_cost);
            }
        }


    }
    graph.drawGridViaSVG(to_string(i), &cost_so_far, reconstruct_path(start, goal, came_from));

}

map<SqPos, int> Dijkstra::reconstruct_path(
                            SqPos start,
                            SqPos goal,
                            map<SqPos, SqPos> came_from)
{
    map<SqPos, int> path;
    SqPos current = goal;
    while (current != start)
    {
        path[current] = 0;
        current = came_from[current];
    }
      path[start];
//    reverse(path.begin(), path.end());
    return path;
}