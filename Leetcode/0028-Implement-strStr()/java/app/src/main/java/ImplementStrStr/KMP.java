package ImplementStrStr;

class KMP {
    private static int[] buildLPS(String s) {
        int[] lps = new int[s.length()];
        // lps[0] = 0;
        // Length of previous LPS
        int len = 0;
        int i = 1;
        while (i < s.length()) {
            if (s.charAt(i) == s.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
                continue;
            }
            // s[i] != s[prevLPS]
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
        return lps;
    }

    public static int search(String txt, String pat) {
        int[] lps = buildLPS(pat);
        int i = 0, j = 0;   // i for txt, j for pat
        while (i < txt.length()) {
            if (txt.charAt(i) == pat.charAt(j)) {
                i++;
                j++;
            } else {
                if (j != 0) {
                    // step back
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
            if (j == pat.length()) {
                return i - pat.length();
            }
        }
        return -1;
    }
}
