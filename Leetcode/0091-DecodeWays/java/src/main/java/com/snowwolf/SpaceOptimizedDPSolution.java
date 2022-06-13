package com.snowwolf;

import java.util.HashMap;
import java.util.Map;

/*
 * When calculating dp[i], only dp[i-1] and dp[i-2] are used.
 * So there's no need to create a dp array.
 */
public class SpaceOptimizedDPSolution {
    public int numDecodings(String s) {
        Map<String, String> codebook = new HashMap<>();
        for (char c = 'A'; c <= 'Z'; c++) {
            String key = String.valueOf(c - 'A' + 1);
            String value = String.valueOf(c);
            codebook.put(key, value);
        }
        int oneBack = (codebook.containsKey(s.substring(0, 1))) ? 1 : 0;        // dp[i-1]
        int twoBack = 1;                                                        // dp[i-2]
        int num = oneBack;
        for (int n = 2; n <= s.length(); n++) {
            num = 0;
            if (codebook.containsKey(s.substring(n - 1, n))) {
                num += oneBack;
            }
            if (codebook.containsKey(s.substring(n - 2, n))) {
                num += twoBack;
            }
            twoBack = oneBack;
            oneBack = num;
        }
        return num;
    }
}
