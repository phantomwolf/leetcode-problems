public class Solution2 {
    public long maximumTripletValue(int[] nums) {
        long maxRes = 0;
        long maxDiff = nums[0] - nums[1];
        long maxI = Math.max(nums[0], nums[1]);
        for (int k = 2; k < nums.length; k++) {
            maxRes = Math.max(maxRes, maxDiff * nums[k]);
            maxDiff = Math.max(maxDiff, maxI - nums[k]);
            maxI = Math.max(maxI, nums[k]);
        }
        return maxRes;
    }
}
