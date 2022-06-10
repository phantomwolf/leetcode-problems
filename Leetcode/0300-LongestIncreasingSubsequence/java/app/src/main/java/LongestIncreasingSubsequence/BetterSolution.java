package LongestIncreasingSubsequence;

import java.util.ArrayList;

public class BetterSolution {
    public int lengthOfLIS(int[] nums) {
        ArrayList<Integer> sub = new ArrayList<>();
        sub.add(nums[0]);
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > sub.get(sub.size() - 1)) {
                sub.add(nums[i]);
            } else {
                int index = binarySearch(sub, nums[i], 0, sub.size() - 1);
                sub.set(index, nums[i]);
            }
        }
        return sub.size();
    }

    private int binarySearch(ArrayList<Integer> sub, int target, int lo, int hi) {
        // [lo, hi]
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            if (sub.get(mi) < target) {
                lo = mi + 1;
            } else if (sub.get(mi) > target) {
                hi = mi - 1;
            } else {
                return mi;
            }
        }
        return lo;
    }
}
