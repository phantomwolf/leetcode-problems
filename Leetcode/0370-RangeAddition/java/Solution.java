import java.util.*;
import java.lang.*;

public class Solution {
    public int[] getModifiedArray(int length, int[][] updates) {
        int[] diff = new int[length];
        for (int[] update : updates) {
            int start = update[0], end = update[1], inc = update[2];
            diff[start] += inc;
            if (end + 1 < length) {
                diff[end + 1] -= inc;
            }
        }
        int[] nums = new int[length];
        nums[0] = diff[0];
        for (int i = 1; i < nums.length; i++) {
            nums[i] = nums[i - 1] + diff[i];
        }
        return nums;
    }

    public static void main(String[] args) {
    }
}

