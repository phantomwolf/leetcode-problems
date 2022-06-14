package com.snowwolf;

public class SpaceOptimizedDPSolution {
    public int numDistinct(String s, String t) {
        int[] dp = new int[t.length() + 1];
        dp[0] = 1;
        for (int i = 1; i <= s.length(); i++) {
            int prev = dp[0];   // dp[i-1][j-1]
            for (int j = 1; j <= t.length(); j++) {
                int tmp = dp[j];
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[j] += prev;
                }
                prev = tmp;
            }
        }
        return dp[t.length()];
    }
}
