#include <iostream>
#include "Graph.hpp"

using namespace std;

int main() {
    Graph graph(9);
    graph.add_edge(0, 1, 2);
    graph.add_edge(0, 3, 3);
    graph.add_edge(1, 2, 2);
    graph.add_edge(1, 4, 7);
    graph.add_edge(2, 5, 2);
    graph.add_edge(3, 4, 7);
    graph.add_edge(3, 6, 6);
    graph.add_edge(4, 5, 4);
    graph.add_edge(4, 7, 4);
    graph.add_edge(5, 8, 2);
    graph.add_edge(6, 7, 4);
    graph.add_edge(7, 8, 5);

    auto mst = graph.get_mst();

    cout << graph << endl;
    cout << mst << endl;
}
