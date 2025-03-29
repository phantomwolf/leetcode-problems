#include <string>
#include <vector>

using namespace std;

class Solution {
 public:
  bool canReach(string s, int minJump, int maxJump) {
    // Define dp[i] as a bool value indicating whether we can reach index i
    vector<bool> dp(s.size());
    // Base case
    dp[0] = true;
    for (int i = 1; i < dp.size(); i++) {
      if (s[i] == '1') {
        dp[i] = false;
        continue;
      }
      // For j in range [i-maxJump, i-minJump], if any dp[j] == true, dp[i] =
      // true
      int left = i - maxJump;
      int right = i - minJump;
      for (int j = max(left, 0); j <= right; j++) {
        if (dp[j]) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[dp.size() - 1];
  }
};
