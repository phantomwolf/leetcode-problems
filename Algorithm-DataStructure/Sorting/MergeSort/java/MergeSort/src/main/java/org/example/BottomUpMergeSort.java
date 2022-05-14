package org.example;

class BottomUpMergeSort {
    BottomUpMergeSort() {
    }

    public static void mergeSort(int[] nums) {
        int N = nums.length;
        int[] aux = new int[N];

        for(int sz = 1; sz < N; sz *= 2) {
            for(int lo = 0; lo < N - sz; lo += sz * 2) {
                int mid = lo + sz - 1;
                int hi = Math.min(lo + sz * 2 - 1, N - 1);
                merge(nums, lo, mid, hi, aux);
            }
        }

    }

    private static void merge(int[] nums, int lo, int mid, int hi, int[] aux) {
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
