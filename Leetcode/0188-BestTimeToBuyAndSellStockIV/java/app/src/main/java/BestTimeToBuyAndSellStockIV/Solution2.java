package BestTimeToBuyAndSellStockIV;

public class Solution2 {
    public int maxProfit(int k, int[] prices) {
        if (prices.length == 0) {
            return 0;
        }
        // Define dp[k][i] as the max profit we can achieve using prices[0, i) with at
        // most k transactions
        int[][] dp = new int[k + 1][prices.length + 1];
        // Base case:
        // 1. When no price or only 1 price available, it's impossible to buy and sell
        // the stock, thus profit is 0: dp[i][0] = 0, dp[i][1] = 0
        // 2. When no transactions allowed, it's impossible to buy/sell stock, thus
        // profit is 0: dp[0][j] = 0
        // In java, the array will be initialized to 0, so nothing needs to be done
        for (int i = 1; i <= k; i++) {
            // We use a variable localMax to track the value of dp[i - 1][m] - prices[m]
            int localMax = Integer.MIN_VALUE;
            for (int j = 2; j <= prices.length; j++) {
                localMax = Math.max(localMax, dp[i - 1][j - 2] - prices[j - 2]);
                dp[i][j] = Math.max(dp[i][j - 1], localMax + prices[j - 1]);
            }
        }
        return dp[k][prices.length];
    }
}
