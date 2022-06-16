package MinimumASCIIDeleteSumForTwoStrings;

public class DPSolution {
    int[][] dp;

    public int minimumDeleteSum(String s1, String s2) {
        // Define dp[i][j] as the lowest ASCII sum of deleted characters to make s1[0,i) and s2[0,j) equal
        dp = new int[s1.length() + 1][s2.length() + 1];
        // base case
        for (int i = 1; i <= s1.length(); i++) {
            dp[i][0] = dp[i - 1][0] + s1.charAt(i - 1);
        }
        for (int j = 1; j <= s2.length(); j++) {
            dp[0][j] = dp[0][j - 1] + s2.charAt(j - 1);
        }
        for (int i = 1; i <= s1.length(); i++) {
            for (int j = 1; j <= s2.length(); j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                    dp[i][j] = dp[i - 1][j - 1];        // No need to delete s1[i-1] and s2[j-1]
                    continue;
                }
                dp[i][j] = Math.min(
                        dp[i - 1][j] + s1.charAt(i - 1),
                        dp[i][j - 1] + s2.charAt(j - 1)
                );
            }
        }
        return dp[s1.length()][s2.length()];
    }

    public String lcs(String s1, String s2) {
        StringBuilder sb = new StringBuilder();
        int i = s1.length(), j = s2.length();
        while (i > 0 && j > 0) {
            if (s1.charAt(i - 1) == s2.charAt(j - 1)) {
                sb.append(s1.charAt(i - 1));
                i--;
                j--;
                continue;
            }
            if (dp[i - 1][j] < dp[i][j - 1])
                i--;
            else
                j--;
        }
        return sb.reverse().toString();
    }
}
