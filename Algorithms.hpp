#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.hpp"

namespace ariel
{
    class Algorithms {
    public:
        static bool isConnected(ariel::Graph g);
        static bool isContainsCycle(ariel::Graph g);
        // std::string shortestPath(ariel::Graph g, int start_node, int end_node);
    };
}

#endif
