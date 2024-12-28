class Solution {
    public int change(int amount, int[] coins) {
        // dp[i][j]: number of combinations that make up i, given coins in range [0, j) are used
        // dp[i][j] = dp[i-coins[j]][j] + dp[i][j-1]
        int[][] dp = new int[amount+1][coins.length+1];
        // Base case
        for (int j = 0; j <= coins.length; j++) {
            dp[0][j] = 1;
        }
        for (int i = 1; i <= amount; i++) {
            for (int j = 1; j <= coins.length; j++) {
                dp[i][j] = dp[i][j-1];
                if (i - coins[j-1] >= 0) {
                    dp[i][j] += dp[i - coins[j-1]][j];
                }
            }
        }

        return dp[amount][coins.length];
    }
}
