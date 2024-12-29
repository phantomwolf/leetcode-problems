package com.snowwolf;

import java.util.Random;

public class SelectionSort {
    public static void main(String[] args) {
        int[] nums = createRandomArray(8848);
        selectionSort(nums);
        if(isSorted(nums)) {
            System.out.printf("Selection sort succeeded\n");
        } else {
            throw new RuntimeException("Selection sort failed");
        }
    }

    public static void selectionSort(int[] nums) {
        // Each time, select the smallest element
        for (int i = 0; i < nums.length; i++) {
            // Find the smallest number in nums[i, nums.length-1]
            int min = i;
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] < nums[min]) {
                    min = j;
                }
            }
            // swap nums[i] and nums[minIndex]
            int tmp = nums[i];
            nums[i] = nums[min];
            nums[min] = tmp;
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
