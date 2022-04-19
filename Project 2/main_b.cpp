#include <iostream>
#include "Graph.hpp"

using namespace std;

int main() {
    Graph graph(7);
    graph.add_edge(0, 1, 11);
    graph.add_edge(0, 2,  2);
    graph.add_edge(0, 3, 10);
    graph.add_edge(0, 5,  9);
    graph.add_edge(1, 3,  5);
    graph.add_edge(1, 4,  3);
    graph.add_edge(2, 5,  8);
    graph.add_edge(3, 4,  6);
    graph.add_edge(3, 5, 13);
    graph.add_edge(3, 6,  7);
    graph.add_edge(4, 6, 12);
    graph.add_edge(5, 6,  4);

    auto mst = graph.get_mst();

    cout << graph << endl;
    cout << mst << endl;
}
