public class Solution2 {
    static final int MOD = (int)1e9 + 7;

    public int numberOfWays(int n, int x) {
        // dp[i][j]: number of ways to get a total sum of `j`. Max allowed base is `i`.
        int maxBase = 1;
        while (pow(maxBase, x) <= n) {
            maxBase++;
        }
        int[] dp = new int[n+1];

        // Base case
        dp[0] = 1;

        for (int i = 1; i < maxBase; i++) {
            for (int j = n; j >= 1; j--) {
                int p = pow(i, x);
                if (p <= j) {
                    dp[j] = (dp[j] + dp[j - p]) % MOD;
                }
            }
        }
        return dp[n];
    }

    private int pow(int base, int x) {
        return (int) Math.pow(base, x);
    }
}