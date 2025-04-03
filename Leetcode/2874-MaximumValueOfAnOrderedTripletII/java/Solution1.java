public class Solution1 {
    public long maximumTripletValue(int[] nums) {
        // rightMax[i] is the max value in range [i+1, nums.length)
        int[] rightMax = new int[nums.length];
        for (int i = nums.length - 2; i >= 0; i--) {
            rightMax[i] = Math.max(rightMax[i + 1], nums[i + 1]);
        }
        // Fix j and calculate result
        long maxRes = 0;
        int maxI = nums[0];
        for (int j = 1; j < nums.length - 1; j++) {
            long res = (long) (maxI - nums[j]) * rightMax[j];
            maxRes = Math.max(maxRes, res);
            maxI = Math.max(maxI, nums[j]);
        }
        return maxRes;
    }
}
