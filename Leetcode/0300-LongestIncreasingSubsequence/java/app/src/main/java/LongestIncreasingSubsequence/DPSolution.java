package LongestIncreasingSubsequence;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

class DPSolution {
    // For each dp[i] = dp[j] + 1, path[i] = j. If dp[i] == 1, path[i] will be -1.
    int[] path;
    int seqEnd = -1;

    public int lengthOfLIS(int[] nums) {
        int longest = Integer.MIN_VALUE;
        // Define dp[i] as the length of the longest increasing subsequence which ends with nums[i]
        int[] dp = new int[nums.length];
        // Record the path
        path = new int[nums.length];
        Arrays.fill(path, -1);
        for (int i = 0; i < nums.length; i++) {
            int max = 1;
            int prev = -1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    // Find a possible candidate for dp[i]
                    int len = dp[j] + 1;
                    if (len > max) {
                        max = len;
                        prev = j;
                    }
                }
            }
            dp[i] = max;
            path[i] = prev;
            // Update overall longest increasing subsequence length
            if (max > longest) {
                longest = max;
                seqEnd = i;
            }
        }
        return longest;
    }

    public List<Integer> lis(int[] nums) {
        List<Integer> seq = new ArrayList<>();
        int i = seqEnd;
        while (i != -1) {
            seq.add(nums[i]);
            i = path[i];
        }
        Collections.reverse(seq);
        return seq;
    }
}
