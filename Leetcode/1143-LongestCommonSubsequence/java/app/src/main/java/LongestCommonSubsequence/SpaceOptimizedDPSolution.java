package LongestCommonSubsequence;

public class SpaceOptimizedDPSolution {
    public int longestCommonSubsequence(String text1, String text2) {
        int[] dp = new int[text2.length() + 1];
        for (int i = 1; i <= text1.length(); i++) {
            int dpi_1j_1 = 0;
            for (int j = 1; j <= text2.length(); j++) {
                if (text1.charAt(i - 1) == text2.charAt(j - 1)) {
                    int tmp = dp[j];
                    dp[j] = dpi_1j_1 + 1;
                    dpi_1j_1 = tmp;
                    continue;
                }
                dpi_1j_1 = dp[j];
                dp[j] = Math.max(dp[j], dp[j - 1]);
            }
        }
        return dp[text2.length()];
    }
}
