#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxJumps(vector<int>& arr, int d) {
    int res = 1;
    unordered_map<int, int> memo;
    for (int i = 0; i < arr.size(); i++) {
      res = max(res, dp(arr, i, d, memo));
    }
    return res;
  }

 private:
  // Return the max numbers of indices I can visit if I start from index i
  int dp(vector<int>& arr, int index, int d, unordered_map<int, int>& memo) {
    auto it = memo.find(index);
    if (it != memo.end()) {
      return it->second;
    }

    int maxIndices = 1;
    for (int i = index - 1; i >= 0 && i >= index - d && arr[index] > arr[i];
         i--) {
      maxIndices = max(maxIndices, dp(arr, i, d, memo) + 1);
    }
    for (int i = index + 1;
         i < arr.size() && i <= index + d && arr[index] > arr[i]; i++) {
      maxIndices = max(maxIndices, dp(arr, i, d, memo) + 1);
    }
    // Save result to memo
    memo[index] = maxIndices;
    return maxIndices;
  }
};
