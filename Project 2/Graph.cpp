#include "Graph.hpp"
#include <climits>

using namespace std;

Graph::Graph(int num_vertices) {
    set_undirected();
    weights = vector<vector<int>>(num_vertices, vector<int>(num_vertices, 0));
    total_weight = 0;
}

void Graph::add_edge(int vertex_a, int vertex_b, int weight) {
    insert_undirected_edge(vertex_a, vertex_b);
    weights[vertex_a][vertex_b] = weight;
    total_weight += weight;
}

Graph Graph::get_mst() {
    Graph mst(num_vertices());
    vector<bool> used(num_vertices(), false);

    // First vertex = true
    used[begin()->first] = true;

    while (mst.num_vertices() != num_vertices()) {
        auto best_a = 0;
        auto best_b = 0;
        auto best_weight = INT_MAX;

        for (const auto vertex : *this) {
            auto a = vertex.first;  // value of vertex/node (0,1,2,3,)

            // second.second = set of neighboring vertices
            for (auto neighbor_vertex : vertex.second.second) {
                auto b = neighbor_vertex;

                // get weight using a and b.
                auto weight = weights[a][b];

                // compare best_weight to weight
                if (used[a] != used[b] && weight < best_weight) {
                    best_a = a;
                    best_b = b;
                    best_weight = weight;
                }
            }
        }

        mst.add_edge(best_a, best_b, best_weight);
        used[best_a] = true;
        used[best_b] = true;
    }

    return mst;
}

std::ostream& operator<<(std::ostream& out, const Graph& graph) {

    out << "Vertices: ";
    for (auto vertex : graph) out << vertex.first << ", ";
    out << endl;

    cout << "Edges: ";
    for (auto vertex : graph)
        for (auto neighbor_vertex : vertex.second.second)
            out << vertex.first << "-" << neighbor_vertex << ", ";
    out << endl;

    out << "Weights: ";
    for (auto vertex : graph)
        for (auto neighbor_vertex : vertex.second.second)
            cout << graph.weights[vertex.first][neighbor_vertex] << ", ";
    out << endl;

    out << "Total Weight: " << graph.total_weight << endl;

    return out;
}
