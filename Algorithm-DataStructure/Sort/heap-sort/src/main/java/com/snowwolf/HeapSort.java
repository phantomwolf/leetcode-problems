package com.snowwolf;

import java.util.Arrays;

public class HeapSort {
    public static void main(String[] args) {
        int[] nums = {4, 10, 3, 5, 1};
        BinaryHeap<Integer> minHeap = new BinaryHeap<>();
        for (int i : nums) {
            minHeap.add(i);
        }
        for (int i = 0; i < nums.length; i++) {
            nums[i] = minHeap.remove();
        }
        if(isSorted(nums)) {
            System.out.printf("Merge sort succeeded\n");
        } else {
            throw new RuntimeException("Merge sort failed");
        }
    }
}
