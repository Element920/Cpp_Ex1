#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
namespace ariel {
    class Graph {
        private:
            std::vector<std::vector<int>> adjMatrix; // Adjacency matrix representation of the graph

        public:
            Graph();
            void loadGraph(std::vector<std::vector<int>>& matrix);
            void printGraph();
            unsigned int getNumVertices() const;
            int getEdgeWeight (unsigned int from, unsigned int to) const;
    };
}
#endif // GRAPH_H



