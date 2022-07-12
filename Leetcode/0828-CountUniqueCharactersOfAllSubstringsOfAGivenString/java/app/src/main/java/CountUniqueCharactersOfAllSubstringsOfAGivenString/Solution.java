package CountUniqueCharactersOfAllSubstringsOfAGivenString;

import java.util.Arrays;

public class Solution {
    public int uniqueLetterString(String s) {
        int res = 0;
        // Save the indexes of the last 2 occurrences
        int[][] last2 = new int[26][2];
        for (int i = 0; i < last2.length; i++) {
            Arrays.fill(last2[i], -1);
        }
        for (int i = 0; i < s.length(); i++) {
            char c = (char) (s.charAt(i) - 'A');
            res += (last2[c][1] - last2[c][0]) * (i - last2[c][1]);
            // Update last2
            last2[c][0] = last2[c][1];
            last2[c][1] = i;
        }
        // Handle last occurrence
        for (int c = 0; c < last2.length; c++) {
            res += (last2[c][1] - last2[c][0]) * (s.length() - last2[c][1]);
        }
        return res;
    }
}
