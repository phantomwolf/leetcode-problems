package findthekthlargestintegerinthearray;

import java.util.Random;

public class QuickSelectSolution {
    final Random random = new Random();

    public String kthLargestNumber(String[] nums, int k) {
        int lo = 0, hi = nums.length - 1;
        while (true) {
            int pivot = partition(nums, lo, hi);
            if (pivot == nums.length - k) {
                return nums[pivot];
            } else if (pivot < nums.length - k) {
                lo = pivot + 1;
            } else {
                hi = pivot - 1;
            }
        }
    }

    int partition(String[] nums, int lo, int hi) {
        int pivot = random.nextInt(hi - lo + 1) + lo;
        // swap pivot with the first element
        String tmp = nums[pivot];
        nums[pivot] = nums[lo];
        nums[lo] = tmp;
        int i = lo + 1, j = hi;
        while (true) {
            while (i <= hi && compare(nums[i], nums[lo]) < 0) {
                i++;
            }
            while (j > lo && compare(nums[j], nums[lo]) > 0) {
                j--;
            }
            if (i >= j) {
                break;
            }
            // swap i and j
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
        // swap lo and j
        tmp = nums[lo];
        nums[lo] = nums[j];
        nums[j] = tmp;
        return j;
    }

    private int compare(final String a, final String b) {
        int lenA = a.length(), lenB = b.length();
        if (lenA != lenB) {
            // Since numbers have no leading zeros, longer ones must be greater than shorter ones
            return lenA - lenB;
        }
        // Compare from the most significant position to least ones
        for (int i = 0; i < lenA; i++) {
            if (a.charAt(i) != b.charAt(i)) {
                return a.charAt(i) - b.charAt(i);
            }
        }
        return 0;
    }
}
