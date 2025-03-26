#include <vector>

using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int currMax = 0;
    int i = 0;
    while (i <= currMax) {
      currMax = max(currMax, i + nums[i]);
      if (currMax >= nums.size() - 1) {
        return true;
      }
      i++;
    }
    return false;
  }
};