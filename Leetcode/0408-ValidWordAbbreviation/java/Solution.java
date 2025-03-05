public class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        int p1 = 0, p2 = 0;
        while (p1 < word.length() && p2 < abbr.length()) {
            if (word.charAt(p1) == abbr.charAt(p2)) {
                p1++;
                p2++;
                continue;
            }
            if (abbr.charAt(p2) <= '0' || abbr.charAt(p2) > '9') {
                return false;
            }
            int p3 = p2;
            while (p3 < abbr.length() && abbr.charAt(p3) >= '0' && abbr.charAt(p3) <= '9') {
                p3++;
            }
            int num = Integer.valueOf(abbr.substring(p2, p3));
            p1 += num;
            p2 = p3;
        }
        if (p1 == word.length() && p2 == abbr.length()) {
            return true;
        }
        return false;
    }
}