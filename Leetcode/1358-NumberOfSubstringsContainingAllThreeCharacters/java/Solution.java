public class Solution {
    public int numberOfSubstrings(String s) {
        int result = 0;
        int[] count = new int[3];
        int matched = 0;
        // For sliding window [i, j), count[] contains the number of 'a', 'b', 'c'
        // and matched means how many of 'a', 'b', 'c' have fulfilled the requirements
        int i = 0, j = 0;   
        while (j < s.length()) {
            // Expand window
            while (j < s.length() && matched < 3) {
                char c = s.charAt(j);
                if (c >= 'a' && c <= 'c') {
                    count[c - 'a']++;
                    if (count[c - 'a'] == 1) {
                        matched++;
                    }
                }
                j++;
            }
            // Shrink window
            int prevI = i;
            while (i < j && matched == 3) {
                char c = s.charAt(i);
                if (c >= 'a' && c <= 'c') {
                    count[c - 'a']--;
                    if (count[c - 'a'] == 0) {
                        matched--;
                    }
                }
                i++;
            }
            // Collect results
            result += (i - prevI) * (s.length() - j + 1);
        }
        return result;
    }
}