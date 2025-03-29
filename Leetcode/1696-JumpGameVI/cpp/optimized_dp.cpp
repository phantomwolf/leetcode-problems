#include <queue>
#include <utility>
#include <vector>

using namespace std;

struct MaxHeapCompare {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
  }
};

class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    // Define dp[i] is the maximum score I can get jumping from 0 to i
    vector<int> dp(nums.size(), 0);
    // Base case
    dp[0] = nums[0];
    // pair: {dp[j], index}
    priority_queue<pair<int, int>, vector<pair<int, int>>, MaxHeapCompare> pq;
    pq.push({dp[0], 0});
    for (int i = 1; i < nums.size(); i++) {
      auto p = pq.top();
      while (p.second < i - k) {
        pq.pop();
        p = pq.top();
      }
      dp[i] = p.first + nums[i];
      // Add dp[i] to pq
      pq.push({dp[i], i});
    }
    return dp[nums.size() - 1];
  }
};