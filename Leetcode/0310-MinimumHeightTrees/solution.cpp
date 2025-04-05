#include <queue>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    // Edge case: when there's only 1 node, its indegree is 0
    if (n == 1) {
      return {0};
    }
    // Build graph
    vector<vector<int>> graph(n);
    vector<int> indegrees(n, 0);
    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
      indegrees[edge[0]]++;
      indegrees[edge[1]]++;
    }
    // Similar to topological sorting, start visiting from nodes with 1 indegree
    queue<int> q;
    for (int u = 0; u < n; u++) {
      if (indegrees[u] == 1) {
        // Push leaf node to queue
        q.push(u);
      }
    }
    int unvisited = n;  // number of unvisited nodes
    while (unvisited > 2) {
      int size = q.size();
      while (size > 0) {
        int u = q.front();
        q.pop();
        unvisited--;
        // Remove indegrees related to u
        indegrees[u] = 0;
        for (int v : graph[u]) {
          indegrees[v]--;
          if (indegrees[v] == 1) {
            // Push the next leaf node to queue
            q.push(v);
          }
        }
        size--;
      }
    }
    // Return result
    vector<int> res;
    while (!q.empty()) {
      res.push_back(q.front());
      q.pop();
    }
    return res;
  }
};
