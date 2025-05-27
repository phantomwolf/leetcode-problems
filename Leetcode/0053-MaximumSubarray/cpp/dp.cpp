#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    // Define dp[i] as the largest sum of an subarray that ends at index i
    vector<int> dp(nums.size(), 0);
    // Base case
    dp[0] = nums[0];
    int maxSum = dp[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = max(dp[i - 1] + nums[i], nums[i]);
      maxSum = max(dp[i], maxSum);
    }
    return maxSum;
  }
};