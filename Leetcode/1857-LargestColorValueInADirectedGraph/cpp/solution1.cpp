#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    // Build the graph
    vector<vector<int>> graph(colors.size());
    vector<int> indegrees(colors.size(), 0);
    for (const vector<int>& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      indegrees[edge[1]]++;
    }
    // Topological sort
    // No need to gather result, because the problem isn't asking for the
    // topological sort result.
    queue<int> q;
    // Count max color values for each color of each node
    vector<vector<int>> count(graph.size(), vector<int>(26, 0));
    for (int u = 0; u < graph.size(); u++) {
      if (indegrees[u] == 0) {
        q.push(u);
      }
    }
    int res = 0;      // result
    int visited = 0;  // number of nodes visited
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      visited++;
      // Add node's own color to count
      count[u][colors[u] - 'a']++;
      // Update result
      res = max(res, count[u][colors[u] - 'a']);

      for (int v : graph[u]) {
        indegrees[v]--;
        // Update color frequency
        char c = colors[v] - 'a';
        for (char i = 0; i < 26; i++) {
          count[v][i] = max(count[v][i], count[u][i]);
        }
        if (indegrees[v] == 0) {
          q.push(v);
        }
      }
    }
    // Cycle exists. Can't finish topological sort
    if (visited < graph.size()) {
      return -1;
    }
    return res;
  }
};
