#include <algorithm>
#include <vector>

using std::sort;
using std::vector;

class Solution {
 public:
  int threeSumSmaller(vector<int>& nums, int target) {
    // Edge case
    if (nums.size() < 3) {
      return 0;
    }

    int res = 0;
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      int j = i + 1, k = nums.size() - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum < target) {
          res += k - j;
          j++;
        } else {
          k--;
        }
      }
    }
    return res;
  }
};
