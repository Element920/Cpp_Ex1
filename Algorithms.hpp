#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.hpp"

namespace ariel
{
    namespace Algorithms {
        bool isConnected(ariel::Graph g);
        bool isContainsCycle(ariel::Graph g);
        // std::string shortestPath(ariel::Graph g, int start_node, int end_node);
    };
}

#endif
