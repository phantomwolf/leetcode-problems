package org.leetcode;

import java.util.Arrays;

class Solution {
    private int count = 0;
    private int[] aux;

    public int reversePairs(int[] nums) {
        aux = new int[nums.length];
        System.out.println(nums.length);
        // Bottom-up merge sort
        for (int sz = 1; sz < nums.length; sz += sz) {
            for (int lo = 0; lo < nums.length - sz; lo += sz + sz) {
                int mid = lo + sz - 1;          // mid < nums.length - 1
                int hi = Math.min(lo + sz + sz - 1, nums.length - 1);
                System.out.printf("lo: %d, mid: %d, hi: %d\n", lo, mid, hi);
                merge(nums, lo, mid, hi);
                System.out.println(Arrays.toString(nums));
            }
        }
        return count;
    }

    // Merge [lo, mid] and [mid + 1, hi]
    private void merge(int[] nums, int lo, int mid, int hi) {
        for (int k = lo; k <= hi; k++)
            aux[k] = nums[k];
        int n = mid + 1;
        for (int m = lo; m <= mid; m++) {
            while (n <= hi &&  Math.ceil((long) nums[m] / 2.0) > (long) nums[n]) {
                n++;
            }
            count += n - mid - 1;
        }
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if (i > mid) {
                nums[k] = aux[j++];
            } else if (j > hi) {
                nums[k] = aux[i++];
            } else if (aux[i] > aux[j]) {
                nums[k] = aux[j++];
            } else {
                nums[k] = aux[i++];
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        int[] nums = {2, 4, 3, 5, 1};
        Solution solution = new Solution();
        int count = solution.reversePairs(nums);
        System.out.println(count);
    }
}