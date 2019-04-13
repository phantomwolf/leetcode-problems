#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        const int int_max = numeric_limits<int>::max();
        // 设d[i]为凑齐i元所需的最少硬币数
        int len = coins.size();
        int *dp = new int[amount + 1];
        int *s  = new int[amount + 1];
        int *buf = new int[len];

        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < len; ++j) {
                if (coins[j] > i) {
                    buf[j] = int_max;
                    continue;
                }
                int remain = i - coins[j];
                if (remain < 0 || dp[remain] == int_max) {
                    buf[j] = int_max;
                    continue;
                }
                buf[j] = dp[i - coins[j]] + 1;
            }
            // Get optimal answer
            dp[i] = buf[0];
            s[i]  = coins[0];
            for (int m = 1; m < len; ++m) {
                if (dp[i] > buf[m]) {
                    dp[i] = buf[m];
                    s[i]  = coins[m];
                }
            }
        }

        // backtrace
        int i = amount;
        cout << "chosen coins: ";
        while (i != 0 && dp[i] != int_max) {
            cout << s[i] << ", ";
            i -= s[i];
        }
        cout << endl;

        int res = dp[amount];
        delete[] buf;
        delete[] dp;
        delete[] s;
        return (res == int_max) ? -1 : res;
    }
};


int main(int argc, char *argv[])
{
    int amount = 12;
    vector<int> coins{1, 2, 5};

    Solution s;
    int res = s.coinChange(coins, amount);
    cout << "result: " << res << endl;
    return 0;
}
