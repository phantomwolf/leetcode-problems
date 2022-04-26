package com.company;

// https://labuladong.github.io/algo/1/12/
class Solution {
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

public class Main {

    public static void main(String[] args) {
	// write your code here
    }
}
