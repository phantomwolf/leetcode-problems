package jumpgameii;

public class DPSolution {
    public int jump(int[] nums) {
        // Define dp[i] as the minimal jumps needed to reach index i
        int[] dp = new int[nums.length];
        dp[0] = 0;      // Base case
        for (int i = 1; i < nums.length; i++) {
            dp[i] = Integer.MAX_VALUE;
            // Try all indexes which can reach i with 1 jump
            for (int j = 0; j < i; j++) {
                if (j + nums[j] >= i) {
                    // i can be reached from index j
                    dp[i] = Math.min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[nums.length - 1];
    }
}
