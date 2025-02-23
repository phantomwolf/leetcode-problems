package com.snowwolf;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class DPSolution {
    public boolean wordBreak(String s, List<String> wordDict) {
        // Add all words to a set
        Set<String> wordSet = new HashSet<>();
        for (String str : wordDict) {
            wordSet.add(str);
        }
        int n = s.length();
        boolean[] dp = new boolean[n+1];
        // base case
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && wordSet.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}
