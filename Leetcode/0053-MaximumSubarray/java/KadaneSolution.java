package MaximumSubarray;

public class KadaneSolution {
    public int maxSubArray(int[] nums) {
        // Max sum of subarray that ends at current location
        int currSum = nums[0];
        // Result
        int maxSum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            currSum = Math.max(currSum+nums[i], nums[i]);
            maxSum = Math.max(currSum, maxSum);
        }
        return maxSum;
    }
}
