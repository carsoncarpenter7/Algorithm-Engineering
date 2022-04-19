#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <ostream>
#include "ngraph.hpp"

class Graph : public NGraph::Graph {
public:
    Graph(int num_vertices);
    void add_edge(int vertex_a, int vertex_b, int weight);
    Graph get_mst();

    std::vector<std::vector<int>> weights;
    int total_weight;
};

std::ostream& operator<<(std::ostream& out, const Graph& graph);

#endif
