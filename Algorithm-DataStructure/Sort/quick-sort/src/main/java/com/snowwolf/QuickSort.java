package com.snowwolf;

import java.util.Arrays;
import java.util.Random;

public class QuickSort {
    private static Random random = new Random();

    private static void swap(int[] nums, int i, int j) {
        if (i == j)
            return;
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    public static void quickSort(int[] nums) {
        quickSort(nums, 0, nums.length - 1);
    }

    public static void quickSort(int[] nums, int lo, int hi) {
        // If there's no or only 1 element in the array
        if (lo >= hi)
            return;
        // Choose a random pivot value
        int pivot = random.nextInt(hi - lo + 1) + lo;
        System.out.printf("lo: %d, pivot: %d, hi: %d\n", lo, nums[pivot], hi);
        // Swap it to the beginning
        swap(nums, lo, pivot);
        int i = lo + 1, j = hi;
        while (true) {
            while (i <= hi && nums[i] < nums[lo])
                i++;
            while (j > lo && nums[j] > nums[lo])
                j--;
            if (i >= j) {
                swap(nums, lo, j);
                break;
            }
            swap(nums, i, j);
            i++;
            j--;
            System.out.printf("nums: %s\n", Arrays.toString(nums));
        }
        System.out.printf("nums: %s\n", Arrays.toString(nums));
        // Sort sub arrays
        quickSort(nums, lo, j - 1);
        quickSort(nums, j + 1, hi);
    }

    public static int[] createRandomArray(int length) {
        int[] nums = new int[length];
        Random random = new Random();
        for (int i = 0; i < nums.length; i++) {
            nums[i] = random.nextInt(999);
        }
        return nums;
    }

    public static boolean isSorted(int[] nums) {
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] > nums[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        int[] nums = createRandomArray(3);
        System.out.printf("nums: %s\n", Arrays.toString(nums));
        quickSort(nums);
        if(isSorted(nums)) {
            System.out.printf("Quick sort succeeded\n");
        } else {
            System.out.println(Arrays.toString(nums));
            throw new RuntimeException("Quick sort failed");
        }
    }
}
