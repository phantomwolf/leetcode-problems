package com.snowwolf;

import java.util.Arrays;
import java.util.Random;

public class InsertionSort {
    public static void main(String[] args) {
        int[] nums = createRandomArray(8848);
        insertionSort(nums);
        if(isSorted(nums)) {
            System.out.printf("Insertion sort succeeded\n");
        } else {
            throw new RuntimeException("Insertion sort failed");
        }
    }

    public static void insertionSort(int[] nums) {
        // Insert 1 item each time
        for (int i = 1; i < nums.length; i++) {
            int tmp = nums[i];
            int j = i - 1;
            while (j >= 0 && nums[j] > tmp) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = tmp;
        }
    }

    public static int[] createRandomArray(int length) {
        int[] nums = new int[length];
        Random random = new Random();
        for (int i = 0; i < nums.length; i++) {
            nums[i] = random.nextInt(10000);
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
