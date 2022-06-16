package LongestPalindromicSubsequence;

public class OptimizedDPSolution {
    public int longestPalindromeSubseq(String s) {
        // Define dp[i][j] as the length of LCS between s[0,i) and its reverse r[0,j)
        int[] dp = new int[s.length() + 1];
        for (int i = 1; i <= s.length(); i++) {
            int dpi_1j_1 = 0;
            for (int j = 1; j <= s.length(); j++) {
                int tmp = dp[j];
                if (s.charAt(i - 1) == s.charAt(s.length() - j)) {
                    dp[j] = dpi_1j_1 + 1;
                    dpi_1j_1 = tmp;
                    continue;
                }
                dp[j] = Math.max(dp[j], dp[j - 1]);
                dpi_1j_1 = tmp;
            }
        }
        return dp[s.length()];
    }
}
