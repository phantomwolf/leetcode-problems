package LongestCommonSubsequence;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class DPSolution {
    int[][] dp;

    public int longestCommonSubsequence(String text1, String text2) {
        StringBuilder sb = new StringBuilder();
        // Define dp[i][j] as the length of longest common subsequence of text1[0,i) and text2[0,j)
        dp = new int[text1.length() + 1][text2.length() + 1];
        for (int i = 1; i <= text1.length(); i++) {
            for (int j = 1; j <= text2.length(); j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    // char word1[i-1] must be in the LCS
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    continue;
                }
                dp[i][j] = Math.max(
                        dp[i - 1][j],       // if text1[i-1] isn't in the LCS
                        dp[i][j - 1]        // if text2[j-1] isn't in the LCS
                );
            }
        }
        return dp[text1.length()][text2.length()];
    }

    // Reversely build the LCS from DP array
    public List<Character> buildLCSFromDP(String text1, String text2) {
        List<Character> lcs = new ArrayList<>();
        int i = text1.length(), j = text2.length();
        while (i > 0 && j > 0) {
            if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                lcs.add(text1.charAt(i - 1));
                i--;
                j--;
                continue;
            }
            if (dp[i - 1][j] < dp[i][j - 1]) {
                j--;
            } else {
                i--;
            }
        }
        Collections.reverse(lcs);
        return lcs;
    }
}
