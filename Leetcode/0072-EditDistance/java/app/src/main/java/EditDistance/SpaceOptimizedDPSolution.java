package EditDistance;

public class SpaceOptimizedDPSolution {
    public int minDistance(String word1, String word2) {
        int[] dp = new int[word2.length() + 1];
        // base case: converting an empty string to word2
        for (int j = 0; j <= word2.length(); j++) {
            dp[j] = j;
        }
        for (int i = 1; i <= word1.length(); i++) {
            int dpi_1j_1 = dp[0];   // dp[i-1][j-1]
            dp[0] = i;
            for (int j = 1; j <= word2.length(); j++) {
                int tmp = dp[j];
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[j] = dpi_1j_1;
                    dpi_1j_1 = tmp;
                    continue;
                }
                dp[j] = min(
                        dp[j - 1] + 1,
                        dp[j] + 1,
                        dpi_1j_1 + 1
                );
                dpi_1j_1 = tmp;
            }
        }
        return dp[word2.length()];
    }

    public int min(int a, int b, int c) {
        int m = (a < b) ? a : b;
        return (m < c) ? m : c;
    }
}
