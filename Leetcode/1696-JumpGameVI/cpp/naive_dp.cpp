#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxResult(vector<int>& nums, int k) {
    // Define dp[i] is the maximum score I can get jumping from 0 to i
    vector<int> dp(nums.size(), 0);
    // Base case
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      // Naive solution: use a loop to find the max dp[j]
      int maxPrevScore = numeric_limits<int>::min();
      for (int j = max(i - k, 0); j < i; j++) {
        maxPrevScore = max(maxPrevScore, dp[j]);
      }
      dp[i] = maxPrevScore + nums[i];
    }
    return dp[nums.size() - 1];
  }
};