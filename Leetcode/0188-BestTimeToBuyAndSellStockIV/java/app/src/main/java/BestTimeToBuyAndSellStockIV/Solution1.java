package BestTimeToBuyAndSellStockIV;

public class Solution1 {
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
            for (int j = 1; j < prices.length; j++) {
                // If we don't sell with prices[j]
                dp[i][j] = dp[i][j - 1];
                // If we decide to sell with prices[j]
                for (int m = 0; m < j; m++) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][m] + prices[j] - prices[m]);
                }
            }
        }
        return dp[k][prices.length - 1];
    }
}
