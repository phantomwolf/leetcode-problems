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
    // For j in range [i-maxJump, i-minJump], how many dp[j] == true are there?
    int count = 0;
    for (int i = 1; i < dp.size(); i++) {
      // Update count
      if (i - minJump >= 0 && dp[i - minJump]) {
        count++;
      }
      if (i - maxJump - 1 >= 0 && dp[i - maxJump - 1]) {
        count--;
      }
      if (s[i] == '1') {
        dp[i] = false;
        continue;
      }
      if (count > 0) {
        dp[i] = true;
      }
    }
    return dp[dp.size() - 1];
  }
};
