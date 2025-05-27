#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    unordered_set<int> set(nums.begin(), nums.end());
    int longestLength = 1;
    for (int num : set) {
      if (set.contains(num - 1)) {
        continue;
      }
      int length = 1;
      int next = num + 1;
      while (set.contains(next)) {
        next++;
        length++;
      }
      longestLength = max(longestLength, length);
    }
    return longestLength;
  }
};