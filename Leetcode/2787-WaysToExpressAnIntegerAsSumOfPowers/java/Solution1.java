class Solution1 {
    static final int MOD = (int)1e9 + 7;

    public int numberOfWays(int n, int x) {
        // dp[i][j]: number of ways to get a total sum of `j` when using elements from 1 to i^x.
        int maxBase = 1;
        while (pow(maxBase, x) <= n) {
            maxBase++;
        }
        int[][] dp = new int[maxBase][n+1];

        // Base cases
        for (int i = 0; i < maxBase; i++) {
            // Only 1 way to get a total sum of 0: select no elements.
            dp[i][0] = 1;
        }

        for (int i = 1; i < maxBase; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i-1][j] % MOD;

                int p = pow(i, x);
                if (p <= j) {
                    dp[i][j] += dp[i-1][j - p] % MOD;
                }
                dp[i][j] %= MOD;
            }
        }
        return dp[maxBase-1][n];
    }

    private int pow(int base, int x) {
        return (int) Math.pow(base, x);
    }
}