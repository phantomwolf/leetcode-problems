package JumpGame;

public class GreedySolution {
    public boolean canJump(int[] nums) {
        // Define last as the last index we can reach(last might be beyond the range of nums)
        int last = 0;
        for (int i = 0; i < nums.length && i <= last; i++) {
            if (i + nums[i] > last) {
                last = nums[i] + i;
            }
            if (last >= nums.length - 1) {
                return true;
            }
        }
        return false;
    }
}