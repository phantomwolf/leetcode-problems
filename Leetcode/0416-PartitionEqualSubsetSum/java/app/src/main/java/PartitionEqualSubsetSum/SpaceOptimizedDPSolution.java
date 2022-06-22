package PartitionEqualSubsetSum;

public class SpaceOptimizedDPSolution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum /= 2;
        boolean[][] dp = new boolean[sum + 1][2];
        // base case
        for (int j = 0; j <= nums.length; j++) {
            dp[0][j % 2] = true;
        }
        for (int j = 1; j <= nums.length; j++) {
            for (int i = 1; i <= sum; i++) {
                if (i >= nums[j - 1]) {
                    dp[i][j % 2] = dp[i - nums[j - 1]][(j - 1) % 2] || dp[i][(j - 1) % 2];
                } else {
                    dp[i][j % 2] = dp[i][(j - 1) % 2];
                }
            }
        }
        return dp[sum][nums.length % 2];
    }
}
