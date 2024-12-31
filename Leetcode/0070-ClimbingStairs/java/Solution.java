class Solution {
    public int climbStairs(int n) {
        // Define dp[i] as the distinct ways to climb to the top(i steps in total)
        int[] dp = new int[n + 1];
        // Base case
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            int[] steps = new int[] { 1, 2 };
            for (int step : steps) {
                if (i - step >= 0) {
                    dp[i] += dp[i - step];
                }
            }
        }
        return dp[n];
    }
}