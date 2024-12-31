package BestTimeToBuyAndSellStockIV;

public class Solution1 {
    public int maxProfit(int k, int[] prices) {
        if (prices.length == 0) {
            return 0;
        }
        // Define dp[i][j] as the max profit we can achieve using prices[0, j) with at
        // most i transactions
        int[][] dp = new int[k + 1][prices.length + 1];
        // Base case:
        // 1. When no price or only 1 price available, it's impossible to buy and sell
        // the stock, thus profit is 0: dp[i][0] = 0, dp[i][1] = 0
        // 2. When no transactions allowed, it's impossible to buy/sell stock, thus
        // profit is 0: dp[0][j] = 0
        // In java, the array will be initialized to 0, so nothing needs to be done
        for (int i = 1; i <= k; i++) {
            for (int j = 2; j <= prices.length; j++) {
                // If we don't sell with prices[j-1]
                dp[i][j] = dp[i][j - 1];
                // If we decide to sell with prices[j-1], we'll have to buy the stock before
                // prices[j-1], which is [0, j-1). Suppose prices[m] is the buying price:
                for (int m = 0; m < j - 1; m++) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][m] + prices[j - 1] - prices[m]);
                }
            }
        }
        return dp[k][prices.length];
    }
}
