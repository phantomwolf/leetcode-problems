package CoinChange;

class Solution {
    public int coinChange(int[] coins, int amount) {
        // Define dp[n] as the fewest number of coins needed to make up an amount of n
        int[] dp = new int[amount + 1];
        // Base case
        dp[0] = 0;
        // Dynamic programming
        for (int n = 1; n <= amount; n++) {
            int min = Integer.MAX_VALUE;
            for (int c : coins) {
                if (c > n || dp[n - c] == -1)
                    continue;
                int count = dp[n - c] + 1;
                if (count < min)
                    min = count;
            }
            dp[n] = (min == Integer.MAX_VALUE) ? -1 : min;
        }
        return dp[amount];
    }
}