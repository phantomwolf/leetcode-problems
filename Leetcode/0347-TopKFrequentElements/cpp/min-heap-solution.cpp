#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    // Calculate the count of each num
    unordered_map<int, int> count;
    for (auto num : nums) {
      count[num]++;
    }
    // Create a min heap with k size
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.first > b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)>
        minHeap(cmp);
    for (auto [n, c] : count) {
      minHeap.push(pair<int, int>{c, n});
      if (minHeap.size() > k) {
        minHeap.pop();
      }
    }

    vector<int> res;
    while (!minHeap.empty()) {
      res.push_back(minHeap.top().second);
      minHeap.pop();
    }
    return res;
  }
};