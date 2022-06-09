import java.util.Arrays;

class BottomUpMergeSort {
    public static void mergeSort(int[] nums) {
        final int N = nums.length;
        int[] aux = new int[N];
        for (int sz = 1; sz < N; sz *= 2) {
            for (int lo = 0; lo < N - sz; lo += sz * 2) {
                int mid = lo + sz - 1;  // Since lo < N - sz, mid =lo + sz - 1 < N - 1
                int hi = Math.min(lo + sz * 2 - 1, N - 1);
                merge(nums, lo, mid, hi, aux);
            }
        }
    }

    // Merge 2 sorted arrays: [lo, mid] and [mid + 1, hi]
    private static void merge(int[] nums, int lo, int mid, int hi, int[] aux) {
        // Copy data from nums to aux
        for (int k = lo; k <= hi; k++)
            aux[k] = nums[k];
        // Merge sort aux[] and write to nums[]
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if (i > mid)
                nums[k] = aux[j++];
            else if (j > hi)
                nums[k] = aux[i++];
            else if (aux[i] <= aux[j])
                nums[k] = aux[i++];
            else
                nums[k] = aux[j++];
        }
    }
}

class TopDownMergeSort {
    private static int[] aux;

    public static void mergeSort(int[] nums) {
        mergeSort(nums, 0, nums.length - 1);
    }

    public static void mergeSort(int[] nums, int lo, int hi) {
        // base case: only 1 element
        if (lo == hi)
            return;

        aux = new int[nums.length];

        int mid = (lo + hi) / 2;    // mid = lo + (hi - lo) / 2
        mergeSort(nums, lo, mid);
        mergeSort(nums, mid + 1, hi);
        merge(nums, lo, mid, hi);
    }

    // Merge 2 sorted arrays: [lo, mid] and [mid + 1, hi]
    private static void merge(int[] nums, int lo, int mid, int hi) {
        // Copy data from nums to aux
        for (int k = lo; k <= hi; k++)
            aux[k] = nums[k];
        // Merge sort aux[] and write to nums[]
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++) {
            if (i > mid)
                nums[k] = aux[j++];
            else if (j > hi)
                nums[k] = aux[i++];
            else if (aux[i] <= aux[j])
                nums[k] = aux[i++];
            else
                nums[k] = aux[j++];
        }
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        int[] nums = {5, 1, 1, 2, 0, 0};
        BottomUpMergeSort.mergeSort(nums);
        System.out.println(Arrays.toString(nums));
        verifySortedArray(nums);
    }

    private static void verifySortedArray(int[] nums) throws Exception {
        if (nums.length == 1)
            return;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i - 1])
                throw new Exception("not sorted");
        }
    }
}