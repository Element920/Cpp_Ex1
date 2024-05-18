#include "Algorithms.hpp"
#include <iostream>
#include <sstream> 
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>


bool ariel::Algorithms::isConnected(ariel::Graph g) {
  uint numNodes = g.getNumVertices();
  std::vector<bool> visited(numNodes, false);
  std::queue<uint> q;
  uint startNode = 0;

  // Mark the start node as visited and enqueue it
  visited[startNode] = true;
  q.push(startNode);

  while (!q.empty()) {
      // Dequeue a node from the queue
      uint currentNode = q.front();
      q.pop();

      // Visit all adjacent nodes of the dequeued node
      for (uint neighbor = 0; neighbor < numNodes; ++neighbor) {
          if (g.getEdgeWeight(currentNode, neighbor) != 0 && !visited[neighbor]) {
              // Mark the adjacent node as visited and enqueue it
              visited[neighbor] = true;
              q.push(neighbor);
          }
      }
  }
  std::vector<bool>::iterator iter = visited.begin();
  for (; iter < visited.end(); iter++) {
    if (!*iter) {
      return false;
    }
  }
  return true;
}

bool ariel::Algorithms::isContainsCycle(ariel::Graph g) {
  uint numNodes = g.getNumVertices();
  uint startNode = 0;
 
  std::vector<bool> visited(numNodes, false);
  std::stack<uint> stack;
  std::vector<int> parent(numNodes, -1);
  stack.push(startNode);
  visited[startNode] = true;

  while (!stack.empty()) {
    uint currentNode = stack.top();
    stack.pop();

    for (uint neighbor = 0; neighbor < numNodes; neighbor++) {
      if (g.getEdgeWeight(currentNode, neighbor) != 0) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          parent[neighbor] = (int)currentNode;
          stack.push(neighbor);
        } else if (parent[currentNode] != neighbor) {
          return true;
        }
      }
    }
  }
  return false;
}


bool ariel::NodeComparator::operator()(const ariel::Node& a, const ariel::Node& b) const {
  return a.distance > b.distance;
}


std::string ariel::Algorithms::shortestPath(const ariel::Graph g, unsigned int startNode, unsigned int endNode) {
  unsigned int numVertices = g.getNumVertices();
  std::vector<bool> visited(numVertices, false);
  std::vector<int> parent(numVertices, -1);

  std::queue<unsigned int> queue;
  queue.push(startNode);
  visited[startNode] = true;

  bool found = false;
  while (!queue.empty() && !found) {
    unsigned int u = queue.front();
    queue.pop();

    for (unsigned int neighbor = 0; neighbor < numVertices; neighbor++) {
      if (g.getEdgeWeight(u,neighbor) > 0 && !visited[neighbor]) {
        visited[neighbor] = true;
        parent[neighbor] = (int) u;
        queue.push(neighbor);

        if (neighbor == endNode) {
          found = true;
          break;
        }
      }
    }
  }

  if (!found) {
    return "-1"; // No path found between startNode and endNode
  }

  // Reconstruct path by backtracking from endNode
  std::vector<unsigned int> path;
  int current = (int) endNode;
  while (current != -1) {
    path.push_back((unsigned int) current);
    current = parent[(size_t)current];
  }

  std::stringstream ss;
  std::reverse(path.begin(), path.end());
  for(size_t i = 0; i < path.size(); ++i) {
    if (i != 0) {
      ss << "->";
    }
    ss << std::to_string(i);
  }

  return ss.str();
}

std::string ariel::Algorithms::isBipartite(ariel::Graph g) {
  unsigned int numVertices = g.getNumVertices();
  std::vector<int> color(numVertices, -1); // -1: uncolored, 0/1: assigned color
  std::vector<unsigned int> set1, set2;
  unsigned int startNode = 0;
  color[startNode] = 1;
 
  // Create a queue (FIFO) of vertex 
  // numbers and enqueue source vertex
  // for BFS traversal
  std::queue<unsigned int> queue;
  queue.push(startNode);
  set1.push_back(startNode);

  // Run while there are vertices 
  // in queue (Similar to BFS)
  while (!queue.empty())
  {
      // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
      unsigned int u = queue.front();
      queue.pop();

      // Return false if there is a self-loop 
      if (g.getEdgeWeight(u,u) > 1)
      return "0";

      // Find all non-colored adjacent vertices
      for (unsigned int v = 0; v < numVertices; ++v)
      {
          // An edge from u to v exists and 
          // destination v is not colored
          if (g.getEdgeWeight(u,v) && color[v] == -1)
          {
              // Assign alternate color to this adjacent v of u
              color[v] = 1 - color[u];
              if(color[v]) {
                set1.push_back(v);
              } else {
                set2.push_back(v);
              }
              queue.push(v);
          }

          // An edge from u to v exists and destination 
          // v is colored with same color as u
          else if (g.getEdgeWeight(u,v) && color[v] == color[u])
            return "0";
      }
  }

  std::stringstream ss;
  ss << "The graph is bipartite: A={";
  for(size_t i = 0; i < set1.size(); ++i)
  {
    if(i != 0)
      ss << ", ";
    ss << set1[i];
  }
  ss << "}, B={";
  for(size_t i = 0; i < set2.size(); ++i)
  {
    if(i != 0)
      ss << ", ";
    ss << set2[i];
  }
  ss << "}";
  return ss.str();
}