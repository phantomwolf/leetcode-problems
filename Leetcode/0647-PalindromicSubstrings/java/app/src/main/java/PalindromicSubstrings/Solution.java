package PalindromicSubstrings;

class Solution {
    public int countSubstrings(String s) {
        int totalCount = 0;
        for (int i = 0; i < s.length(); i++) {
            totalCount += expandFromCenter(s, i, i);
        }
        for (int i = 1; i < s.length(); i++) {
            totalCount += expandFromCenter(s, i - 1, i);
        }
        return totalCount;
    }

    // Returns the number of palindromic substrings
    private int expandFromCenter(String s, int i, int j) {
        int count = 0;
        while (i >= 0 && j < s.length() && s.charAt(i) == s.charAt(j)) {
            count++;
            i--;
            j++;
        }
        return count;
    }
}