package com.snowwolf;

import java.util.*;

class Solution {
    private static void swap(int[] nums, int i, int j) {
        if (i == j) {
            return;
        }
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    private static void quickSort(int[] nums, int lo, int hi) {
        if (lo >= hi)
            return;
        Random random = new Random();
        int pivot = random.nextInt(hi - lo + 1) + lo;
        swap(nums, lo, pivot);
        int i = lo + 1, j = hi;
        while (true) {
            while (i <= hi && nums[i] < nums[lo]) {
                i++;
            }
            while (j > lo && nums[j] > nums[lo]) {
                j--;
            }
            if (i >= j) {
                // partitioning finished
                swap(nums, lo, j);
                break;
            }
            swap(nums, i, j);
            i++;
            j--;
        }
        quickSort(nums, lo, j - 1);
        quickSort(nums, j + 1, hi);
    }

    public int[] advantageCount(int[] nums1, int[] nums2) {
        int[] sortedNums1 = nums1.clone(), sortedNums2 = nums2.clone();
        quickSort(sortedNums1, 0, sortedNums1.length - 1);
        quickSort(sortedNums2, 0, sortedNums2.length - 1);
        // Numbers in nums1 which can't defeat any element in nums2
        Queue<Integer> sacrifice = new LinkedList<>();
        // Mapping between nums1 and nums2, so that nums1[i] > nums[j]
        Map<Integer, Queue<Integer>> match = new HashMap<>();
        int i = 0, j = 0;
        while (i < sortedNums1.length && j < sortedNums2.length) {
            if (sortedNums1[i] <= sortedNums2[j]) {
                sacrifice.add(sortedNums1[i]);
                i++;
            } else {
                Queue<Integer> q;
                if (match.containsKey(sortedNums2[j])) {
                    q = match.get(sortedNums2[j]);
                } else {
                    q = new LinkedList<>();
                    match.put(sortedNums2[j], q);
                }
                q.add(sortedNums1[i]);
                i++;
                j++;
            }
        }
        for (int k = 0; k < nums2.length; k++) {
            if (match.containsKey(nums2[k]) && !match.get(nums2[k]).isEmpty()) {
                sortedNums1[k] = match.get(nums2[k]).remove();
            } else {
                sortedNums1[k] = sacrifice.remove();
            }
        }
        return sortedNums1;
    }
}