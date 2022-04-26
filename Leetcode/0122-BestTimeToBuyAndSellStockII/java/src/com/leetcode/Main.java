package com.leetcode;

class DPSolution {
    public int maxProfit(int[] prices) {
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        // dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
        int[][] dp = new int[prices.length + 1][2];
        dp[0][1] = Integer.MIN_VALUE;
        for (int i = 1; i <= prices.length; i++) {
            int price = prices[i - 1];
            dp[i][0] = Math.max(dp[i - 1][0], dp[i - 1][1] + price);
            dp[i][1] = Math.max(dp[i - 1][1], dp[i - 1][0] - price);
        }
        return dp[prices.length][0];
    }
}

class Solution {
    public int maxProfit(int[] prices) {
        int totalProfit = 0;
        boolean descending = true;
        int valley = Integer.MAX_VALUE, peak = Integer.MIN_VALUE;
        for (int i = 0; i < prices.length; i++) {
            int next = (i + 1 >= prices.length) ? Integer.MIN_VALUE : prices[i + 1];
            if (descending && prices[i] < next) {
                valley = prices[i];
                descending = false;
            } else if (!descending && prices[i] > next) {
                peak = prices[i];
                descending = true;
                // calculate profit
                totalProfit += peak - valley;
            }
        }
        return totalProfit;
    }
}
public class Main {
    public static void main(String[] args) {
    }
}
