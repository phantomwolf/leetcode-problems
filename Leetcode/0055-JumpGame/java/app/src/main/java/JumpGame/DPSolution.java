package JumpGame;


class DPSolution {
    public boolean canJump(int[] nums) {
        // Define dp[i] as the farmost index we can jump to from nums[0] to nums[i]
        int[] dp = new int[nums.length];
        
        // Base case
        dp[0] = nums[0];
        if (dp[0] >= nums.length-1) {
            return true;
        }

        for (int i = 1; i < dp.length; i++) {
            if (dp[i-1] < i) {
                return false;
            }
            dp[i] = Math.max(dp[i-1], i + nums[i]);
            if (dp[i] >= nums.length-1) {
                return true;
            }
        }
        return false;
    }
}