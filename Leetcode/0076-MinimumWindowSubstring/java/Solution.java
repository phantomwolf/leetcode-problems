class Solution {
    public String minWindow(String s, String t) {
        // Base case
        if (s.length() < t.length()) {
            return "";
        }

        int[] countT = new int[128];
        int matched = 128;
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            countT[c]++;
            if (countT[c] == 1) {
                matched--;
            }
        }
        // Sliding window
        int start = -1, end = s.length();
        int[] countS = new int[128];
        int left = 0, right = 0;
        while (right < s.length()) {
            char c = s.charAt(right);
            right++;
            if (countT[c] > 0) {
                countS[c]++;
                if (countS[c] == countT[c]) {
                    matched++;
                }
            }
            while (matched == 128) {
                if (right-left < end-start) {
                    end = right;
                    start = left;
                }
                char d = s.charAt(left);
                left++;
                if (countT[d] > 0) {
                    if (countS[d] == countT[d]) {
                        matched--;
                    }
                    countS[d]--;
                }
            }
        }
        if (start == -1) {
            return "";
        }
        return s.substring(start, end);
    }
}