
#include "Graph.hpp"

ariel::Graph::Graph() {}


void ariel::Graph::loadGraph(std::vector<std::vector<int>>& matrix) {
    // if (matrix.size() != V || matrix[0].size() != V) {
    //     std::cout << "Error: Invalid adjacency matrix dimensions." << std::endl;
    //     return;
    // }
    V = matrix.size();
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

int ariel::Graph::getEdgeWeight(unsigned int from, unsigned int to) const
{
    return adjMatrix[from][to];
}

unsigned int ariel::Graph::getNumVertices() const {
    return adjMatrix.size();
}

std::vector<std::vector<int>> ariel::Graph::getAdjMatrix() {
    return adjMatrix;
}