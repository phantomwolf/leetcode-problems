package JumpGame;

public class DPSolution {
    public boolean canJump(int[] nums) {
        if (nums.length == 1) {
            return true;
        }
        // Define dp[i] as the farthest index can be reached with nums[0, i]
        int[] dp = new int[nums.length];
        dp[0] = nums[0];
        int currMax = Integer.MIN_VALUE;
        for (int i = 1; i < nums.length; i++) {
            currMax = Math.max(dp[i - 1], currMax);
            if (currMax < i) {
                return false;
            }
            dp[i] = Math.max(currMax, i + nums[i]);
            if (dp[i] >= nums.length - 1) {
                return true;
            }
        }
        return false;
    }
}
