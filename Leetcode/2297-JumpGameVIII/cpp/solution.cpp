#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct MinHeapCompare {
  bool operator()(pair<long long, int>& a, pair<long long, int>& b) {
    return a.first > b.first;
  }
};

class Solution {
 public:
  long long minCost(vector<int>& nums, vector<int>& costs) {
    unordered_map<int, vector<int>> graph;
    vector<pair<long long, int>> stack1{{nums[0], 0}};
    vector<pair<long long, int>> stack2{{nums[0], 0}};
    for (int i = 1; i < nums.size(); i++) {
      // Next greater element
      while (!stack1.empty() && nums[i] >= stack1.back().first) {
        graph[stack1.back().second].push_back(i);
        stack1.pop_back();
      }
      stack1.push_back({nums[i], i});
      // Next smaller element
      while (!stack2.empty() && nums[i] < stack2.back().first) {
        graph[stack2.back().second].push_back(i);
        stack2.pop_back();
      }
      stack2.push_back({nums[i], i});
    }
    // Print graph
    /*for (auto [u, lst] : graph) {
        cout << u << ": ";
        for (auto v : lst) {
            cout << v << ", ";
        }
        cout << endl;
    }*/
    // Dijkstra
    vector<long long> dist(nums.size(), numeric_limits<long long>::max());
    dist[0] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   MinHeapCompare>
        pq;
    pq.push({dist[0], 0});
    while (!pq.empty()) {
      // d is distance, u is a node in the graph
      auto [d, u] = move(pq.top());
      pq.pop();
      // Neighbors
      for (int v : graph[u]) {
        if (d + costs[v] < dist[v]) {
          dist[v] = d + costs[v];
          pq.push({dist[v], v});
        }
      }
    }
    return dist[nums.size() - 1];
  }
};
