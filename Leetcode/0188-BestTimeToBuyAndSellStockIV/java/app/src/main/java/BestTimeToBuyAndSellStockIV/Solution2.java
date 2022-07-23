package BestTimeToBuyAndSellStockIV;

public class Solution2 {
    public int maxProfit(int k, int[] prices) {
        if (prices.length == 0) {
            return 0;
        }
        // Define dp[k][i] as the max profit using prices[0, i] with at most k transactions
        int[][] dp = new int[k + 1][prices.length];
        // Base case: with java, all values in the array will be initialized to 0
        /*for (int i = 0; i <= k; i++) {
            // No prices can be used. Profit is 0
            dp[i][0] = 0;
        }
        for (int j = 0; j < prices.length; j++) {
            // No transactions allowed. Profit is 0
            dp[0][j] = 0;
        }*/
        for (int i = 1; i <= k; i++) {
            int localMax = dp[i - 1][0] - prices[0];
            for (int j = 1; j < prices.length; j++) {
                dp[i][j] = Math.max(dp[i][j - 1], localMax + prices[j]);
                localMax = Math.max(localMax, dp[i - 1][j] - prices[j]);
            }
        }
        return dp[k][prices.length - 1];
    }
}
