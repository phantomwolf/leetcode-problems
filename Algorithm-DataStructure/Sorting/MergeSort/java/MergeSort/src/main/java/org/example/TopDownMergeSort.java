package org.example;

class TopDownMergeSort {
    private static int[] aux;

    TopDownMergeSort() {
    }

    public static void mergeSort(int[] nums) {
        mergeSort(nums, 0, nums.length - 1);
    }

    public static void mergeSort(int[] nums, int lo, int hi) {
        if (lo != hi) {
            aux = new int[nums.length];
            int mid = (lo + hi) / 2;
            mergeSort(nums, lo, mid);
            mergeSort(nums, mid + 1, hi);
            merge(nums, lo, mid, hi);
        }
    }

    private static void merge(int[] nums, int lo, int mid, int hi) {
        int i;
        for(i = lo; i <= hi; ++i) {
            aux[i] = nums[i];
        }

        i = lo;
        int j = mid + 1;

        for(int k = lo; k <= hi; ++k) {
            if (i > mid) {
                nums[k] = aux[j++];
            } else if (j > hi) {
                nums[k] = aux[i++];
            } else if (aux[i] <= aux[j]) {
                nums[k] = aux[i++];
            } else {
                nums[k] = aux[j++];
            }
        }
    }
}
