package com.company;

// https://labuladong.github.io/algo/1/12/
class DPSolution1 {
    public int maxProfit(int k, int[] prices) {
        // dp[i][j][m]: the max profit we can get on the ith day if we can make j transactions at most
        //      i: day. i = 1 means the first day(first element of prices)
        //      j: max transaction count allowed.
        //      m: status. m = 1 means holding stocks; m = 0 means not holding stocks.

        int dp[][][] = new int[prices.length + 1][k + 1][2];    // by default, profit is 0
        for (int i = 0; i <= k; i++) {
            // The day before the first day, it's impossible to hold any stocks
            dp[0][i][1] = Integer.MIN_VALUE;
        }
        for (int i = 0; i <= prices.length; i++) {
            // If max transaction count is 0, it's impossible to hold any stocks
            dp[i][0][1] = Integer.MIN_VALUE;
        }
        // for each day
        for (int i = 1; i <= prices.length; i++) {
            // for each allowed transaction count
            for (int j = 1; j <= k; j++) {
                // 1. User didn't sell stock yesterday
                // 2. User sold stock yesterday
                dp[i][j][0] = Math.max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i - 1]);
                // 1. User didn't buy stock yesterday
                // 2. User bought stock yesterday
                dp[i][j][1] = Math.max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i - 1]);
            }
        }
        return dp[prices.length][k][0];
    }
}

class DPSolution2 {
/*
 * dp[i][j] = maximum profit from at most i transactions using prices[0..j]
 * A transaction is defined as one buy + sell. Buying stock alone doesn't change the profit
 * Now on day j, we have two options
 *      1. Do nothing (or buy stock) which doesn't change the acquired profit: dp[i][j] = dp[i][j-1]
 *      2. Sell the stock: In order to sell the stock, you must've bought it on a day t = [0..j-1].
 *         Maximum profit that can be attained is: t∈[0..j-1], max(prices[j] - prices[t] + dp[i-1][t-1]),
 *         where prices[j] - prices[t] is the profit from buying on day t and selling on day j,
 *         and dp[i-1][t-1] is the maximum profit that can be made with at most i-1 transactions with prices prices[0..t-1].
 *         For a given j, max(prices[j] - prices[t] + dp[i-1][t-1]) = prices[j] + max(dp[i-1][t-1] - prices[t]).
 *         The value of max(dp[i-1][t-1] - prices[t]) can be calculated by tracking the value of dp[i-1][t-1] - prices[t] with a variable.
 *
 *         和上一个解法的区别是，没有最后一个维度来表示是否持有股票。要在第j天卖出股票，就必须在第t天买入股票(t∈[0..j-1])，但我们并不知道在哪一天买入才能使利润最大，于是只好求解max(prices[j] - prices[t] + dp[i-1][t-1])
 */
    public int maxProfit(int k, int[] prices) {
        int[][] dp = new int[k + 1][prices.length];
        // base case
        // dp[0][n] = 0: No transactions allowed. Profit is 0
        // dp[n][0] = 0: Only 1 prices is allowed. Profit is 0
        // dp[n][-1] = 0: No prices allowed. Profit is 0.
        for (int i = 1; i <= k; i++) {
            int tmpMax = -prices[0];        // tmpMax is used for tracking the value of: dp[i-1][t] - prices[t]
            for (int j = 1; j < prices.length; j++) {
                dp[i][j] = Math.max(dp[i][j - 1], prices[j] + tmpMax);
                tmpMax = Math.max(tmpMax, dp[i - 1][j - 1] - prices[j]);
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
    }
}
