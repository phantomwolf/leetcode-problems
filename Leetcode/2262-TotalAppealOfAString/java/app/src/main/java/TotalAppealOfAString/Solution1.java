package TotalAppealOfAString;

import java.util.Arrays;

public class Solution1 {
    public long appealSum(String s) {
        long result = 0;
        int[] last = new int[26];
        Arrays.fill(last, -1);
        for (int i = 0; i < s.length(); i++) {
            // Record the index of last char
            last[s.charAt(i) - 'a'] = i;
            for (int j : last) {
                if (j == -1)
                    continue;
                result += j + 1;
            }
        }
        return result;
    }
}
