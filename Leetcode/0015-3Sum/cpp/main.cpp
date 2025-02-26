#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution1 {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    // Sort nums
    std::sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; i = nextUniqueIndex(nums, i)) {
      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum < 0) {
          j = nextUniqueIndex(nums, j);
        } else if (sum > 0) {
          k = prevUniqueIndex(nums, k);
        } else {
          // Collect result
          res.push_back(vector<int>{nums[i], nums[j], nums[k]});
          j = nextUniqueIndex(nums, j);
          k = prevUniqueIndex(nums, k);
        }
      }
    }
    return res;
  }

 private:
  int nextUniqueIndex(vector<int>& nums, int index) {
    index++;
    while (index < nums.size() && nums[index] == nums[index - 1]) {
      index++;
    }
    return index;
  }

  int prevUniqueIndex(vector<int>& nums, int index) {
    index--;
    while (index >= 0 && nums[index] == nums[index + 1]) {
      index--;
    }
    return index;
  }
};

class Solution2 {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.size() < 3) return res;
    sort(nums.begin(), nums.end());
    unordered_set<int> s;
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i != 0 && nums[i] == nums[i - 1]) {
        continue;
      }
      int target = -nums[i];
      s.clear();
      for (int j = i + 1; j < nums.size(); ++j) {
        if (j != nums.size() - 1 && nums[j] == nums[j + 1]) {
          s.insert(nums[j]);
          continue;
        }
        cout << i << ": " << nums[i] << ", " << j << ": " << nums[j] << endl;
        if (s.find(target - nums[j]) != s.end()) {
          res.push_back(vector<int>{nums[i], target - nums[j], nums[j]});
        }
        s.insert(nums[j]);
      }
    }
    return res;
  }
};

int main() {
  vector<vector<int>> res;
  vector<int> nums{0, 0, 0, 0};

  Solution1 s1;
  res = s1.threeSum(nums);
  for (int i = 0; i < res.size(); ++i) {
    for (int j = 0; j < res[i].size(); ++j) {
      cout << res[i][j] << ", ";
    }
    cout << endl;
  }
  return 0;
}
