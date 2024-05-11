
#include "Graph.hpp"

ariel::Graph::Graph() {}

ariel::Graph::Graph(int vertices) : V(vertices) {
    adjMatrix.resize((unsigned long)V, std::vector<int>((unsigned long)V, 0)); // Initialize the matrix with 0s
}

void ariel::Graph::loadGraph(std::vector<std::vector<int>>& matrix) {
    if (matrix.size() != V || matrix[0].size() != V) {
        std::cout << "Error: Invalid adjacency matrix dimensions." << std::endl;
        return;
    }

    adjMatrix = matrix;
}

void ariel::Graph::printGraph() {
    std::cout << "Graph with " << V << " vertices and ";
    int edges = 0;
    for (uint i = 0; i < V; ++i) {
        for (uint j = i + 1; j < V; ++j) {
            if (adjMatrix[i][j])
                edges++;
        }
    }
    std::cout << edges << " edges." << std::endl;
}