// israelmor555@gmail.com
// 206508954

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "Graph.hpp"

namespace ariel
{
  class Algorithms
  {
  public:
    static bool isConnected(ariel::Graph g);
    static bool isContainsCycle(ariel::Graph g);
    static std::string shortestPath(ariel::Graph g, uint startNode, uint endNode);
    static std::string isBipartite(ariel::Graph g);
    static bool negativeCycle(const ariel::Graph g);
  };

}

#endif
