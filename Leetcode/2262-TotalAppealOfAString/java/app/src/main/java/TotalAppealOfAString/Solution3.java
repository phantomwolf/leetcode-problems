package TotalAppealOfAString;

import java.util.Arrays;

public class Solution3 {
    public long appealSum(String s) {
        int last[] = new int[26];
        Arrays.fill(last, -1);
        long res = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            res += (i - last[c - 'a']) * (s.length() - i);
            last[c] = i;
        }
        return res;
    }
}