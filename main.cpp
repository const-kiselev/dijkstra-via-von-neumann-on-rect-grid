#include "dijkstra.h"

int main() {
    srand(time(NULL));
    int i,j,k,l;
    cin >> i >> j;
    Grid g(i,j);
    cout << "Start: "; cin >> i >> j;
    cout << "Goal: "; cin >> k >> l;
    Dijkstra::search(g, SqPos(i,j), SqPos(k,l));
    return 0;
}