class Solution {
    public int combinationSum4(int[] nums, int target) {
        // Define dp[i] as the number of possible combinations that sum up to target.
        // To get a combination, first we put nums[j] in the end, then we figure out the other part.
        // dp[i] = dp[i-nums[0]] + dp[i-nums[1]] + ... + dp[i-nums[nums.length-1]]
        int[] dp = new int[target+1];
        // Base case: there's only 1 combination that sums up to 0, which is an empty set.
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.length; j++) {
                int remain = i - nums[j];
                if (remain >= 0) {
                    dp[i] += dp[remain];
                }
            }
        }
        return dp[target];
    }
}

