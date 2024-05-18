
#include "Graph.hpp"

ariel::Graph::Graph() {}


void ariel::Graph::loadGraph(std::vector<std::vector<int>>& matrix) {
    unsigned int numVertices = matrix.size();
    if (matrix[0].size() != numVertices ) {
        throw std::invalid_argument("Error: Invalid adjacency matrix dimensions.");
        return;
    }
    adjMatrix = matrix;
}

void ariel::Graph::printGraph() {
    unsigned int numVertices = getNumVertices();
    std::cout << "Graph with " << numVertices << " vertices and ";
    int edges = 0;
    for (unsigned int i = 0; i < numVertices; ++i) {
        for (unsigned int j = 0; j < numVertices; ++j) {
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
