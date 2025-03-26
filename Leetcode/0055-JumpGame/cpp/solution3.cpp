#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    // Define dp[i] as the largest index we can reach from any position inside
    // range [0, i]
    vector<int> dp(nums.size());
    // Base case
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      // Max index can be reached from previous positions
      int maxIndexFromPrev = std::numeric_limits<int>::min();
      for (int j = 0; j < i; j++) {
        maxIndexFromPrev = max(dp[j], maxIndexFromPrev);
      }
      if (maxIndexFromPrev < i) {
        // Index i can't be reached.
        // If we can reach the last index, i will absolutely be reachable. Since
        // i can't reached, we can't reach the last index
        return false;
      }
      dp[i] = max(maxIndexFromPrev, i + nums[i]);
    }
    return true;
  }
};
