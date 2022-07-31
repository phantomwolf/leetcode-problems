package jumpgameii;

public class GreedySolution {
    public int jump(int[] nums) {
        // [start, end] is the range of indexes we can reach within current jump
        int start = 0, end = 0;
        int jumps = 0;
        while (end < nums.length - 1) {
            int nextEnd = Integer.MIN_VALUE;
            for (int i = start; i <= end; i++) {
                nextEnd = Math.max(nextEnd, i + nums[i]);
            }
            if (nextEnd > end) {
                start = end + 1;
                end = nextEnd;
                jumps++;
            } else {
                // can't go any farther
                return -1;
            }
        }
        return jumps;
    }
}
