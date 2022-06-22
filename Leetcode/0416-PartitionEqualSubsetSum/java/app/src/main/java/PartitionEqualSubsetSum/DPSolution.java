package PartitionEqualSubsetSum;

public class DPSolution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0) {
            return false;
        }
        sum /= 2;
        boolean[][] dp = new boolean[sum + 1][nums.length + 1];
        // base case
        for (int j = 0; j <= nums.length; j++) {
            dp[0][j] = true;
        }
        for (int i = 1; i <= sum; i++) {
            for (int j = 1; j <= nums.length; j++) {
                if (i >= nums[j - 1]) {
                    dp[i][j] = dp[i - nums[j - 1]][j - 1] || dp[i][j - 1];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
        return dp[sum][nums.length];
    }
}
