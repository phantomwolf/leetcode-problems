package com.snowwolf;

import java.util.Random;

public class MergeSort {
    public static void main(String[] args) {
        int[] nums = createRandomArray(8848);
        mergeSort(nums);
        if(isSorted(nums)) {
            System.out.printf("Merge sort succeeded\n");
        } else {
            throw new RuntimeException("Merge sort failed");
        }
    }

    public static void mergeSort(int[] nums) {
        int[] aux = new int[nums.length];
        for (int sz = 1; sz < nums.length - 1; sz *= 2) {
            for (int lo = 0; lo < nums.length - sz; lo += sz * 2) {
                // Since nums[mi + 1] is the first item of the 2nd array to be merged, mi + 1 = (lo + sz - 1) + 1 < nums.length - 1
                int mi = lo + sz - 1;
                // Becareful of out of index error
                int hi = Math.min(lo + sz + sz - 1, nums.length - 1);
                merge(nums, lo, mi, hi, aux);
            }
        }
    }

    // Merge [lo, mi] and [mi + 1, hi]
    public static void merge(int[] nums, int lo, int mi, int hi, int[] aux) {
        // Write nums[lo, hi] to aux[lo, hi]
        for (int k = lo; k <= hi; k++) {
            aux[k] = nums[k];
        }
        // Merge
        int i = lo, j = mi + 1;
        for (int k = lo; k <= hi; k++) {
            if (i > mi)
                nums[k] = aux[j++];
            else if (j > hi)
                nums[k] = aux[i++];
            else if (nums[i] > nums[j])
                nums[k] = nums[j++];
            else
                nums[k] = nums[i++];
        }
    }

    public static int[] createRandomArray(int length) {
        int[] nums = new int[length];
        Random random = new Random();
        for (int i = 0; i < nums.length; i++) {
            nums[i] = random.nextInt(99999);
        }
        return nums;
    }

    public static boolean isSorted(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] > nums[i])
                return false;
        }
        return true;
    }
}
