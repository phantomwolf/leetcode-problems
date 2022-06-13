package com.snowwolf;

import java.util.HashMap;
import java.util.Map;

class DPSolution {
    public int numDecodings(String s) {
        Map<String, String> codebook = new HashMap<>();
        for (char c = 'A'; c <= 'Z'; c++) {
            String key = String.valueOf(c - 'A' + 1);
            String value = String.valueOf(c);
            codebook.put(key, value);
        }
        // Define dp[i] as the number of ways to decode a substring with length i
        int[] dp = new int[s.length() + 1];
        dp[0] = 1;
        for (int n = 1; n <= s.length(); n++) {
            for (int i = n - 1; i >= 0 && i >= n - 2; i--) {
                String key = s.substring(i, n);
                if (codebook.containsKey(key)) {
                    dp[n] += dp[i];
                }
            }
        }
        return dp[s.length()];
    }
}