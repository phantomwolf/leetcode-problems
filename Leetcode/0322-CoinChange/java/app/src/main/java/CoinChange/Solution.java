package CoinChange;

class Solution {
    public int coinChange(int[] coins, int amount) {
        // dp[i]: the min number of coins that can make up amount `i`
        int[] dp = new int[amount+1];
        for (int i = 1; i <= amount; i++) {
            dp[i] = Integer.MAX_VALUE;
            for (int coin : coins) {
                if (coin > i || dp[i - coin] == -1) {
                    // Impossible to get amount `i` using this coin
                    continue;
                }
                dp[i] = Math.min(dp[i], dp[i - coin] + 1);
            }
            if (dp[i] == Integer.MAX_VALUE) {
                dp[i] = -1;
            }
        }
        return dp[amount];
    }
}
