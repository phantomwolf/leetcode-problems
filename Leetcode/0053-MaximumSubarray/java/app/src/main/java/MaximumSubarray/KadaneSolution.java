package MaximumSubarray;

public class KadaneSolution {
    public int maxSubArray(int[] nums) {
        int maxSum = nums[0];
        int currSum = nums[0];
        for (int i = 1; i < nums.length; i++) {
            currSum = Math.max(currSum + nums[i], nums[i]);
            if (currSum > maxSum) {
                maxSum = currSum;
            }
        }
        return maxSum;
    }
}
