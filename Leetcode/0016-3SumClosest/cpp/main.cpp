#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::sort;
using std::vector;

class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    int closestSum = nums[0] + nums[1] + nums[2];

    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i++) {
      int j = i + 1, k = nums.size() - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == target) {
          return target;
        }
        if (abs(sum - target) < abs(closestSum - target)) {
          closestSum = sum;
        }
        if (sum < target) {
          j++;
        } else {
          k--;
        }
      }
    }
    return closestSum;
  }
};

int main() {
  Solution s;
  vector<int> nums{-1, 2, 1, -4};
  int target = 1;
  int res = s.threeSumClosest(nums, target);
  cout << "Result: " << res << endl;
  return 0;
}
