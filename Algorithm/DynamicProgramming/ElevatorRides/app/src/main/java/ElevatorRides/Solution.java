package ElevatorRides;

public class Solution {
    /*
     * @param weights       weights of all people
     * @param capacity      load capacity of the elevator
     */
    public int elevatorRides(int[] weights, int capacity) {
        int[][] dp = new int[1 << weights.length][2];
        // base case
        dp[0][0] = 1;
        dp[0][1] = 0;
        for (int mask = 1; mask < (1 << weights.length); mask++) {
            int ans = weights.length;
            for (int i = 0; i < weights.length; i++) {
                if (((1 << i) & mask) == 0)
                    continue;
                int newMask = (1 << i) ^ mask;
                if (dp[newMask][1] + weights[i] <= capacity) {
                    dp[mask] = min(dp[mask], new int[]{dp[newMask][0], dp[newMask][1] + weights[i]});
                } else {
                    dp[mask] = min(dp[mask], new int[]{dp[newMask][0] + 1, weights[i]});
                }
            }
        }
        return dp[(1 << weights.length) - 1][0];
    }

    private int[] min(int[] dp1, int[] dp2) {
        if (dp1[0] == dp2[0])
            return (dp1[1] < dp2[1]) ? dp1 : dp2;
        return (dp1[0] < dp2[0]) ? dp1 : dp2;
    }
}
