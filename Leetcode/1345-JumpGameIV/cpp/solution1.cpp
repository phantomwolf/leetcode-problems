#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int minJumps(vector<int>& arr) {
    unordered_map<int, vector<int>> valToIndexes;
    for (int i = 0; i < arr.size(); i++) {
      valToIndexes[arr[i]].push_back(i);
    }

    // BFS
    queue<int> q;  // stores indexes
    vector<bool> visited(arr.size(), false);
    // Add first node
    q.push(0);
    visited[0] = true;
    int steps = 0;
    while (!q.empty()) {
      int size = q.size();
      for (int i = 0; i < size; i++) {
        int index = q.front();
        q.pop();
        // Check if reached last index
        if (index == arr.size() - 1) {
          return steps;
        }
        // Visit neighbors
        if (index - 1 >= 0 && !visited[index - 1]) {
          visited[index - 1] = true;
          q.push(index - 1);
        }
        if (index + 1 < arr.size() && !visited[index + 1]) {
          visited[index + 1] = true;
          q.push(index + 1);
        }
        // Visit same values
        for (int nextIndex : valToIndexes[arr[index]]) {
          if (visited[nextIndex]) {
            continue;
          }
          visited[nextIndex] = true;
          q.push(nextIndex);
        }
        // Clear the value because they're already visited
        // Next time we visit the same value of arr[index], we won't repeatedly
        // visit all indexes with the same value again.
        valToIndexes[arr[index]].clear();
      }
      steps++;
    }
    return -1;
  }
};