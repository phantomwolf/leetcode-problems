package com.snowwolf;

public class SpaceOptimizedDPSolution {
    public int numDistinct(String s, String t) {
        int[] dp = new int[t.length() + 1];
        for (int i = 1; i <= s.length(); i++) {
            int prev = 1;
            for (int j = 1; j <= t.length(); j++) {
                if (s.charAt(i - 1) == t.charAt(j - 1)) {
                    dp[i][j] += prev;
                }
                dp[i][j] += dp[j];          // dp[j] = dp[i-1][j]
                dp[j] = dp[i][j];
            }
        }
        return dp[s.length()][t.length()];
    }
}
