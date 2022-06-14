package EditDistance;

public class DPSolution {
    public int minDistance(String word1, String word2) {
        // Define dp[i][j] as the edit distance of word1[0, i) and word2[0, j)
        int[][] dp = new int[word1.length() + 1][word2.length() + 1];
        // base case
        for (int i = 0; i <= word1.length(); i++) {
            // To convert "word1" to an empty string "word2", just delete all characters. There won't be any faster way
            dp[i][0] = i;
        }
        for (int j = 0; j <= word2.length(); j++) {
            // To convert an empty string "word1" to "word2", just insert all characters of "word2". There won't be any faster way
            dp[0][j] = j;
        }
        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];
                    continue;
                }
                dp[i][j] = min(
                        dp[i][j - 1] + 1,       // insert: first convert word1[0, i) to word2[0,j-1), then insert word2[j-1]
                        dp[i - 1][j] + 1,       // delete: first convert word1[0,i-1) to word2[0,j), then delete word1[i-1]
                        dp[i - 1][j - 1] + 1    // replace: first convert word1[0,i-1) to word2[0,j-1), then replace word1[i-1] with word2[j-1]
                );
            }
        }
        return dp[word1.length()][word2.length()];
    }

    public int min(int a, int b, int c) {
        int m = (a < b) ? a : b;
        return (m < c) ? m : c;
    }
}
