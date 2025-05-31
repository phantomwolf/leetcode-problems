#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // Edge case
        int n = prices.size();
        if (n == 1) {
            // Only 1 day. Can't perform transaction.
            return 0;
        }

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(k+1, vector<int>(2, 0)));
        /* On i-th day, if we already have stock in our hand,
         * we can choose to either sell stock in our hand, or rest:
         *      dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1]+prices[i])
         *      buying + selling is considered as one transaction. To make the codes simple, we only consider buying as consuming a transaction. Selling won't decrease transaction.
         * if we don't have stock in our hand, we can choose to buy or rest:
         *      dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0]-prices[i])
         * If any value is out of index, treat it as min int
         */

        // Base case
        // dp[0][j][0] = 0 because this is the first day and we can't sell stock to reach status 0: the only possibility is "rest"
        // dp[0][j][1] = -prices[0] because we can buy stock 
        // dp[i][0][s] = 0 because no transactions allowed
        for (int j = 1; j <= k; j++) {
            dp[0][j][1] = -prices[0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j][1] = max(
                    dp[i-1][j][1],              // rest
                    dp[i-1][j-1][0]-prices[i]   // buy stock
                );
                //printf("dp[%d][%d][1]: %d\n", i, j, dp[i][j][1]);
                dp[i][j][0] = max(
                    dp[i-1][j][0],              // rest
                    dp[i-1][j][1]+prices[i]     // sell stock
                );
                //printf("dp[%d][%d][0]: %d\n", i, j, dp[i][j][0]);
            }
        }
        return dp[n-1][k][0];
    }
};
