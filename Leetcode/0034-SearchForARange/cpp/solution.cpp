#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    if (nums.size() == 0) {
      return {-1, -1};
    }
    int left = searchLeftBoundary(nums, target);
    if (left == -1) {
      return {-1, -1};
    }
    int right = searchRightBoundary(nums, target);
    return {left, right};
  }

  int searchLeftBoundary(vector<int>& nums, int target) {
    // [l, r)
    int l = 0, r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] > target) {
        r = m;
      } else if (nums[m] < target) {
        l = m + 1;
      } else {
        // Although we've found the target, we need to keep searching the left
        // boundary
        r = m;
      }
    }
    if (l < nums.size() && nums[l] == target) {
      return l;
    }
    return -1;
  }

  int searchRightBoundary(vector<int>& nums, int target) {
    // [l, r)
    int l = 0, r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (nums[m] > target) {
        r = m;
      } else if (nums[m] < target) {
        l = m + 1;
      } else {
        // Although we've found the target, we need to keep searching the right
        // boundary
        l = m + 1;
      }
    }
    if (l - 1 < nums.size() && nums[l - 1] == target) {
      return l - 1;
    }
    return -1;
  }
};