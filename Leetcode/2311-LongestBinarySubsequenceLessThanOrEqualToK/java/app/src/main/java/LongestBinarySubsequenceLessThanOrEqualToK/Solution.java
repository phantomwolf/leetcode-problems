package LongestBinarySubsequenceLessThanOrEqualToK;

public class Solution {
    public int longestSubsequence(String s, int k) {
        int res = 0;
        long cost = 1;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '1' && cost <= k) {
                k -= cost;
                res++;
            } else if (s.charAt(i) == '0') {
                res++;
            }
            // Update cost.
            // Stop increasing cost if it's already greater than current k to avoid overflowing.
            if (cost <= k) {
                cost <<= 1;
            }
        }
        return res;
    }
}