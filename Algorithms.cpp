#include "Algorithms.hpp"

bool ariel::Algorithms::isConnected(ariel::Graph g) {
  std::vector<std::vector<int>> adj_matrix = g.getAdjMatrix();
  uint num_nodes = adj_matrix.size();
  std::vector<bool> visited(num_nodes, false);
  std::queue<uint> q;
  uint start_node = 0;

  // Mark the start node as visited and enqueue it
  visited[start_node] = true;
  q.push(start_node);

  while (!q.empty()) {
      // Dequeue a node from the queue
      uint current_node = q.front();
      q.pop();

      // Visit all adjacent nodes of the dequeued node
      for (uint neighbor = 0; neighbor < num_nodes; ++neighbor) {
          if (adj_matrix[current_node][neighbor] == 1 && !visited[neighbor]) {
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