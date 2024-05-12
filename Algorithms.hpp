#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream> 

#include "Graph.hpp"

namespace ariel
{
    namespace Algorithms {
        bool isConnected(ariel::Graph g);
        // std::string shortestPath(ariel::Graph g, int start_node, int end_node);

    };
}

#endif
