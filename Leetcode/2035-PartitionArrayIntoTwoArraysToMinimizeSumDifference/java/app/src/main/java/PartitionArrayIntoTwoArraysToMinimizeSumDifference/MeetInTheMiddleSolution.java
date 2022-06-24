package PartitionArrayIntoTwoArraysToMinimizeSumDifference;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class MeetInTheMiddleSolution {
    public int minimumDifference(int[] nums) {
        // Subset sums by sizes
        int N = nums.length / 2;
        List<List<Integer>> leftSums = calcSubsetSums(nums, 0, N);
        List<List<Integer>> rightSums = calcSubsetSums(nums, N, N);
        // Total sum
        int sum = 0;
        for (int n : nums) {
            sum += n;
        }
        // Sort subset sums of the right part
        for (List<Integer> lst : rightSums) {
            lst.sort(new Comparator<Integer>() {
                public int compare(Integer a, Integer b) {
                    return a - b;
                }
            });
        }
        // Find the minimal difference
        int minDiff = Integer.MAX_VALUE;
        for (int sz = 0; sz <= N; sz++) {
            for (int a : leftSums.get(sz)) {
                // Minimize |(sum - (a + b)) - (a + b)| = |sum - 2a - 2b|
                int b = (sum - 2*a) / 2;
                int rsz = N - sz;
                int closest = search(rightSums.get(rsz), b);
                int diff = Math.abs(sum - 2 * a - 2 * closest);
                minDiff = Math.min(minDiff, diff);
            }
        }
        return minDiff;
    }

    // Calculate the sum of all subsets and group them by their sizes
    private List<List<Integer>> calcSubsetSums(int[] nums, int start, int length) {
        List<List<Integer>> subsetSums = new ArrayList<>();
        for (int sz = 0; sz <= length; sz++) {
            subsetSums.add(new ArrayList<>());
        }
        for (int mask = 0; mask < (1 << length); mask++) {
            int sz = 0;
            int sum = 0;
            for (int j = 0; j < length; j++) {
                if ((mask & (1 << j)) != 0) {
                    sz++;
                    sum += nums[j + start];
                }
            }
            subsetSums.get(sz).add(sum);
        }
        return subsetSums;
    }

    // Use binary search to find the closest number to target.
    // In other words, minimize |nums[i] - target|
    private int search(List<Integer> nums, int target) {
        if (nums.size() == 0)
            return 0;
        int lo = 0, hi = nums.size() - 1;
        // [lo, hi]
        while (lo <= hi) {
            int mi = lo + (hi - lo) / 2;    // avoid overflow
            if (nums.get(mi) == target) {
                return target;
            } else if (nums.get(mi) < target) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
        // If target not found, nums[hi] < target and nums[lo] > target
        if (lo >= nums.size()) {
            return nums.get(hi);
        } else if (hi < 0) {
            return nums.get(lo);
        } else if (Math.abs(nums.get(lo) - target) < Math.abs(nums.get(hi) - target)) {
            return nums.get(lo);
        } else {
            return nums.get(hi);
        }
    }
}
