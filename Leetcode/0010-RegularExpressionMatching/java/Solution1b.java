class Solution1b {
    public boolean isMatch(String s, String p) {
        // Define dp[i][j] as whether s[i...] and p[j...] matches
        boolean[][] dp = new boolean[s.length() + 1][p.length() + 1];

        // Base case: pattern exhausted
        dp[s.length()][p.length()] = true;
        /*
         * Default value of dp[i][j] is already false. Nothing needs to be done
         * for (int i = s.length() - 1; i >= 0; i--) {
         * dp[i][p.length()] = false;
         * }
         */
        // dp[s.length()][j] can be calculated from dp[0][j+2], no need to deal with
        // this base case
        for (int i = s.length(); i >= 0; i--) {
            for (int j = p.length() - 1; j >= 0; j--) {
                if (i < s.length() && (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.')) {
                    if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
                        // case 1: 'p[j]*' matches 0 characters
                        boolean cand1 = dp[i][j + 2];
                        // case 2: 'p[j]*' matches 1 or more characters
                        boolean cand2 = dp[i + 1][j];
                        dp[i][j] = cand1 || cand2;
                    } else {
                        // p[j+1] is not '*'. Just do a simple 1 character match.
                        dp[i][j] = dp[i + 1][j + 1];
                    }
                    // s[i] and p[j] doesn't match. The only hope of matching is p[j+1] is '*', so
                    // that it can match 0 characters.
                } else if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
                    dp[i][j] = dp[i][j + 2];
                } /*
                   * else {
                   * //Default value of dp[i][j] is false. No need to assign false to it.
                   * dp[i][j] = false;
                   * }
                   */

            }
        }
        return dp[0][0];
    }
}