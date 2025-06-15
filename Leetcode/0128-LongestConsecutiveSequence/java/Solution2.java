import java.util.HashSet;

public class Solution2 {
    public int longestConsecutive(int[] nums) {
        // Edge case
        if (nums.length == 0) {
            return 0;
        }

        HashSet<Integer> set = new HashSet<>();
        for (int n : nums) {
            set.add(n);
        }
        int longest = 0;
        for (int n : set) {
            if (set.contains(n-1)) {
                continue;
            }
            int i = n+1;
            while (set.contains(i)) {
                i++;
            }
            int length = i-n;
            longest = Math.max(longest, length);
        }
        return longest;
    }
}
