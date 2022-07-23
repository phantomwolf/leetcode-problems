package BestTimeToBuyAndSellStockWithTransactionFee;

public class Solution {
    public int maxProfit(int[] prices, int fee) {
        // Define dp[i] as the max profit we can get using prices[0, i]
        int[] dp = new int[prices.length];
        // base case: on day 0, we can't sell, so profit is 0
        int tmpMax = Integer.MIN_VALUE;
        for (int i = 1; i < prices.length; i++) {
            // If we don't sell on day i
            dp[i] = dp[i - 1];
            // If we sell stock on day i
            int prevProfit = (i - 2 >= 0) ? dp[i - 2] : 0;
            tmpMax = Math.max(tmpMax, prevProfit - prices[i - 1]);
            dp[i] = Math.max(dp[i - 1], tmpMax + prices[i] - fee);
        }
        return dp[prices.length - 1];
    }
}
