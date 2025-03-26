#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    unordered_set<int> visited;
    return dfs(nums, 0, visited);
  }

 private:
  bool dfs(vector<int>& nums, int index, unordered_set<int>& visited) {
    if (index == nums.size() - 1) {
      return true;
    }
    // Visit neighboring nodes: [index+1, index+nums[index]]
    for (int i = index + 1; i < nums.size() && i <= index + nums[index]; i++) {
      if (visited.find(i) != visited.end()) {
        // Index i already visited
        continue;
      }
      visited.insert(i);
      if (dfs(nums, i, visited)) {
        return true;
      }
    }
    return false;
  }
};

/* Verification:
Input: nums = [2,3,1,1,4]
Output: true

0: range [1, 2]
1: range [2, 4]
2: range [3, 3]
3: range [4, 4]
4: destination
*/