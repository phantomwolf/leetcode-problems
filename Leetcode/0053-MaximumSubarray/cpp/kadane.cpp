#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    // Base case
    int sum = nums[0];
    int maxSum = sum;
    for (int i = 1; i < nums.size(); i++) {
      sum = max(sum + nums[i], nums[i]);
      maxSum = max(sum, maxSum);
    }
    return maxSum;
  }
};