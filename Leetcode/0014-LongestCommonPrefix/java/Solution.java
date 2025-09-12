public class Solution {
    public String longestCommonPrefix(String[] strs) {
        // Corner case
        if (strs.length == 1) {
            return strs[0];
        }

        int i = 0;
        while (i < strs[0].length()) {
            char c = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (i >= strs[j].length() || strs[j].charAt(i) != c) {
                    return strs[0].substring(0, i);
                }
            }
            i++;
        }
        return strs[0].substring(0, i);
    }
}
