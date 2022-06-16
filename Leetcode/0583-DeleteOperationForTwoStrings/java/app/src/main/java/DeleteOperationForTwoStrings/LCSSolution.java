package DeleteOperationForTwoStrings;

public class LCSSolution {
    public int minDistance(String word1, String word2) {
        int[] dp = new int[word2.length() + 1];
        for (int i = 1; i <= word1.length(); i++) {
            int dpi_1j_1 = 0;
            for (int j = 1; j <= word2.length(); j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    int tmp = dp[j];
                    dp[j] = dpi_1j_1 + 1;
                    dpi_1j_1 = tmp;
                    continue;
                }
                dpi_1j_1 = dp[j];
                dp[j] = Math.max(dp[j], dp[j - 1]);
            }
        }
        int lcsLength = dp[word2.length()];
        return (word1.length() -  lcsLength) + (word2.length() - lcsLength);
    }
}
