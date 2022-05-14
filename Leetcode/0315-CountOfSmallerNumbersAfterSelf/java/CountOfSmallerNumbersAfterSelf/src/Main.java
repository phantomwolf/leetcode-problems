
import java.lang.*;
import java.util.*;
import java.util.stream.Collectors;

class Solution {
    private class Pair {
        public int val;
        public int index;

        Pair(int val, int index) {
            this.val = val;
            this.index = index;
        }

        public String toString() {
            return String.format("%d(%d)", val, index);
        }
    }

    private int[] counts;
    private Pair[] aux;

    public List<Integer> countSmaller(int[] nums) {
        aux = new Pair[nums.length];
        counts = new int[nums.length];
        // Create an array of Pair
        Pair[] pairs = new Pair[nums.length];
        for (int k = 0; k < nums.length; k++)
            pairs[k] = new Pair(nums[k], k);
        for (int sz = 1; sz < nums.length; sz *= 2) {
            for (int lo = 0; lo < nums.length - sz; lo += sz * 2) {
                int mid = lo + sz - 1;      // mid < nums.length - 1, so that mid + 1 < nums.length
                int hi = Math.min(lo + sz * 2 - 1, nums.length - 1);
                merge(pairs, lo, mid, hi);
            }
        }
        return Arrays.stream(counts).boxed().collect(Collectors.toList());
    }

    // Merge [lo, mid] and [mid+1, hi]
    // 当写入nums[i]时，j已经前进的距离，就是nums[i]右边比它小的值的数量
    private void merge(Pair[] pairs, int lo, int mid, int hi) {
        // copy data from input to aux
        int i = lo, j = mid + 1;
        for (int k = lo; k <= hi; k++)
            aux[k] = pairs[k];
        System.out.println(Arrays.toString(pairs));
        System.out.printf("lo: %d, mid: %d, hi: %d\n", lo, mid, hi);
        for (int k = lo; k <= hi; k++) {
            if (i > mid) {
                pairs[k] = aux[j++];
            } else if (j > hi) {
                counts[aux[i].index] += j - mid - 1;
                pairs[k] = aux[i++];
            } else if (aux[i].val <= aux[j].val) {
                counts[aux[i].index] += j - mid - 1;
                pairs[k] = aux[i++];
            } else {
                pairs[k] = aux[j++];
            }
        }
        System.out.println(Arrays.toString(pairs));
    }
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {-1, -1};
        List<Integer> counts = solution.countSmaller(nums);
        System.out.println(counts);
    }
}