#include <limits>
#include <vector>

using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int left = 0, right = 0;
    int steps = 0;
    while (true) {
      if (right == nums.size() - 1) {
        return steps;
      }

      int currMax = numeric_limits<int>::min();
      for (int i = left; i <= right; i++) {
        currMax = max(currMax, i + nums[i]);
      }
      // Update range
      if (currMax <= right) {
        // Can't jump farther
        return -1;
      }
      left = right + 1;
      right = min(currMax, static_cast<int>(nums.size() - 1));
      steps++;
    }
  }
};
/* Verification:
Input: nums = [2,3,1,1,4]
Output: 2

*/