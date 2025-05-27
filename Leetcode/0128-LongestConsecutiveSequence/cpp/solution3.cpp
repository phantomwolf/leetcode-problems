#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    // Sort input array
    std::sort(nums.begin(), nums.end());

    int length = 1;
    int longest = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1] + 1) {
        length++;
        longest = max(longest, length);
      } else if (nums[i] == nums[i - 1]) {
        continue;
      } else {
        length = 1;
      }
    }
    return longest;
  }
};