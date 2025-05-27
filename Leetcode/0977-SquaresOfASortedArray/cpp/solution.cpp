#include <cmath>

class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> res;
    // Find the boundary of negative and positive elements
    int i = 0;
    while (i < nums.size() && nums[i] < 0) {
      i++;
    }
    int j = i - 1;
    while (j >= 0 || i < nums.size()) {
      int val;
      if (j < 0) {
        val = nums[i];
        i++;
      } else if (i >= nums.size()) {
        val = nums[j];
        j--;
      } else if (abs(nums[j]) < abs(nums[i])) {
        val = nums[j];
        j--;
      } else {
        val = nums[i];
        i++;
      }
      res.push_back(val * val);
    }
    return res;
  }
};