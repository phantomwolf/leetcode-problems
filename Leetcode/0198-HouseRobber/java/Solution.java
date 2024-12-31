class Solution {
    public int rob(int[] nums) {
        // Define dp[i] as the maximum amount of money you can rob froms nums[0, i)
        int[] dp = new int[nums.length + 1];
        // Base case: only 1 house
        dp[1] = nums[0];
        for (int i = 2; i <= nums.length; i++) {
            // Two possibilities:
            // 1. Rob nums[i-1] and don't rob nums[i-2]
            // 2. Rob nums[i-2] and don't rob nums[i-1]
            dp[i] = Math.max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[nums.length];
    }
}