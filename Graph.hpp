#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
namespace ariel {
        class Graph {
            private:
                int V; // Number of vertices
                std::vector<std::vector<int>> adjMatrix; // Adjacency matrix representation of the graph

            public:
                Graph();
                Graph(int vertices);
                void loadGraph(std::vector<std::vector<int>>& matrix);
                void printGraph();
        };
}
#endif // GRAPH_H



