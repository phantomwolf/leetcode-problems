package BestTimeToBuyAndSellStockWithCooldown;

public class OptimizedDPSolution {
    public int maxProfit(int[] prices) {
        // Define dp[i] as the max profit we can get with prices[0..i]
        int[] dp = new int[prices.length];
        // Use variable localMax to track the max value of dp[j-2] - prices[j]
        int localMax = Integer.MIN_VALUE;
        for (int i = 1; i < prices.length; i++) {
            int tmp = (i - 3 >= 0) ? dp[i - 3] : 0;
            localMax = Math.max(localMax, tmp - prices[i - 1]);
            dp[i] = Math.max(dp[i - 1], localMax + prices[i]);
        }
        return dp[prices.length - 1];
    }
}
