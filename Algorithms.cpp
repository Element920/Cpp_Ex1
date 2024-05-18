#include "Algorithms.hpp"
#include <iostream>
#include <sstream> 
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <vector>

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
  std::vector<std::vector<int>> adj_matrix = g.getAdjMatrix();
  uint num_nodes = adj_matrix.size();
  uint start_node = 0;
 
  std::vector<bool> visited(num_nodes, false);
  std::stack<uint> stack;
  std::vector<int> parent(num_nodes, -1);
  stack.push(start_node);
  visited[start_node] = true;

  while (!stack.empty()) {
    uint current = stack.top();
    stack.pop();

    for (uint neighbor = 0; neighbor < num_nodes; neighbor++) {
      if (g.getEdgeWeight(current, neighbor) != 0) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          parent[neighbor] = (int)current;
          stack.push(neighbor);
        } else if (parent[current] != neighbor) {
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

std::string shortestPath(ariel::Graph g, uint start_node, uint end_node) {
  // std::vector<std::vector<int>> adj_matrix = g.getAdjMatrix();
  // uint num_nodes = adj_matrix.size();
  // std::vector<int> distance(num_nodes, std::numeric_limits<int>::max()); // Initialize distances to infinity
  // std::vector<int> parent(num_nodes, -1); // Track parent for path reconstruction
  // std::vector<bool> visited(num_nodes, false);

  // distance[start_node] = 0; // Distance from source to itself is 0
  // std::priority_queue<std::pair<uint, int>, std::vector<std::pair<uint, int>>, std::greater<std::pair<uint, int>>> pq;
  // pq.push({0, start_node}); // Push source with distance 0

  // while (!pq.empty()) {
  //   std::pair<uint, int> u = pq.top(); // Extract vertex with minimum distance
  //   pq.pop();

  //   if (visited[u.first]) {
  //     continue;
  //   }

  //   visited[u.first] = true;

  //   for (uint v = 0; v < num_nodes; v++) {
  //     if (adj_matrix[u.first][v] > 0 && !visited[v]) { // Check for valid edge and unvisited neighbor
  //       int newDist = distance[u.first] + adj_matrix[u.first][v];
  //       if (newDist < distance[v]) {
  //         distance[v] = newDist;
  //         parent[v] = u.first; // Update parent for path reconstruction
  //         pq.push({distance[v], v});
  //       }
  //     }
  //   }
  // }

  // if (distance[end_node] == std::numeric_limits<int>::max()) {
  //   return "-1"; // No path found
  // }

  // // Reconstruct the path string (reverse order)
  // std::string path;
  // uint current = end_node;
  // while (current != -1) {
  //   path = std::to_string(current) + " -> " + path;
  //   current = parent[current];
  // }
  // path = path.substr(0, path.size() - 4); // Remove trailing " -> "

  // return start_node == end_node ? std::to_string(start_node) : path; // Handle source-to-source case
  return "-1";
}

std::string ariel::Algorithms::isBipartite(ariel::Graph g) {
  std::vector<std::vector<int>> adj_matrix = g.getAdjMatrix();
  uint num_nodes = adj_matrix.size();
  std::vector<int> color(num_nodes, -1); // -1: uncolored, 0/1: assigned color
  std::vector<uint> set1, set2;

  for (uint v = 0; v < num_nodes; ++v) {
    if (color[v] == -1) {
      // Assign color 0 to the source vertex
      color[v] = 0;
      set1.push_back(v);
      std::queue<uint> q;
      q.push(v);

      while (!q.empty()) {
        uint u = q.front();
        q.pop();

        // Check for adjacent vertices with the same color
        for (uint neighbor = 0; neighbor < num_nodes; neighbor++) {
          if (adj_matrix[u][neighbor] == 1 && color[neighbor] == color[u]) {
            return "0"; // Not Bipartite (adjacent with same color)
          }

          // Assign alternate color to uncolored adjacent vertices
          if (adj_matrix[u][neighbor] == 1 && color[neighbor] == -1) {
            color[neighbor] = 1 - color[u];
            if (color[neighbor] == 0) {
              set1.push_back(neighbor);
            } else {
              set2.push_back(neighbor);
            }
            q.push(neighbor);
          }
        }
      }
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