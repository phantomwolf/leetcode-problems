package com.snowwolf;

public class ZeroOneKnapsack {
    public static int knapsack(int capacity, int[] wt, int[] val) {
        int[][] dp = new int[capacity + 1][wt.length + 1];
        // base case
        for (int i = 0; i <= capacity; i++) {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= wt.length; j++) {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= capacity; i++) {
            for (int j = 1; j <= wt.length; j++) {
                int w = wt[j - 1];
                if (i >= w) {
                    dp[i][j] = Math.max(dp[i - w][j - 1] + val[j - 1], dp[i][j - 1]);
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[capacity][wt.length];
    }

    // Space optimized DP
    public static int knapsack2(int capacity, int[] wt, int[] val) {
        int[][] dp = new int[capacity + 1][2];
        for (int j = 1; j <= wt.length; j++) {
            for (int i = 1; i <= capacity; i++) {
                int w = wt[j - 1];
                if (i >= w) {
                    dp[i][j % 2] = Math.max(dp[i - w][(j - 1) % 2] + val[j - 1], dp[i][(j - 1) % 2]);
                } else {
                    dp[i][j % 2] = dp[i][(j - 1) % 2];
                }
            }
        }
        return dp[capacity][wt.length % 2];
    }

    public static void main(String[] args) {
        int capacity = 4;
        int[] wt = {2, 1, 3};
        int[] val = {4, 2, 3};
        int maxValue = knapsack2(capacity, wt, val);
        System.out.printf("Max value: %d%n", maxValue);
    }
}