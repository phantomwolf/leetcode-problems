package BestTimeToBuyAndSellStockWithCooldown;

public class DPSolution {
    public int maxProfit(int[] prices) {
        // Define dp[i] as the max profit we can get with prices[0..i]
        int[] dp = new int[prices.length];
        for (int i = 1; i < prices.length; i++) {
            // If we didn't sell on day i
            dp[i] = dp[i - 1];
            // If we sell stock on day i
            for (int j = 0; j < i; j++) {
                // Suppose stock was bought on day j,
                // which also means we can't sell stock on day j - 1
                int prevProfit = (j - 2 >= 0) ? dp[j - 2] : 0;
                dp[i] = Math.max(dp[i], prevProfit + prices[i] - prices[j]);
            }
        }
        return dp[prices.length - 1];
    }
}
