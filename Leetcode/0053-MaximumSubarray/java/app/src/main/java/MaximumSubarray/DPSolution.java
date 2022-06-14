package MaximumSubarray;

public class DPSolution {
    public int maxSubArray(int[] nums) {
        int maxSum = Integer.MIN_VALUE;
        // Define dp[i] as the maxium sum of all subarrays which ends with nums[i - 1]
        int[] dp = new int[nums.length + 1];
        // dp[0] = 0
        for (int i = 1; i <= nums.length; i++) {
            if (dp[i - 1] > 0) {
                dp[i] = dp [i - 1] + nums[i - 1];
            } else {
                dp[i] = nums[i - 1];
            }
            // Update overall max sum
            if (dp[i] > maxSum)
                maxSum = dp[i];
        }
        return maxSum;
    }
}
