package KthLargestElementInAnArray;

import java.util.Random;

public class QuickSelectSolution {
    Random random = new Random();

    public int findKthLargest(int[] nums, int k) {
        int lo = 0, hi = nums.length - 1;
        while (lo <= hi) {
            int mi = partition(nums, lo, hi);
            if (mi == nums.length - k) {
                return nums[mi];
            }
            if (mi < nums.length - k) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
        return -1;
    }

    private int partition(int[] nums, int lo, int hi) {
        int mi = random.nextInt(hi - lo + 1) + lo;
        // swap nums[lo] and nums[mi]
        swap(nums, lo, mi);
        int i = lo + 1, j = hi;
        while (true) {
            while (i <= hi && nums[i] < nums[lo]) {
                i++;
            }
            while (j > lo && nums[j] > nums[lo]) {
                j--;
            }
            if (i >= j) {
                break;
            }
            // swap nums[i] and nums[j]
            swap(nums, i, j);
            i++;
            j--;
        }
        swap(nums, lo, j);
        return j;
    }

    private void swap(int[] nums, int i, int j) {
        if (i == j)
            return;
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}
