package KMP;

public class KMP {
    String p;
    int[] lps;

    // @param p     pattern
    public KMP(String p) {
        this.p = p;
        lps = buildLPSArray(p);
    }

    private int[] buildLPSArray(String p) {
        int[] lps = new int[p.length()];
        // lps[0] = 0;
        int len = 0;    // previous lps length
        int i = 1;      //
        while (i < p.length()) {
            if (p.charAt(i) == p.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
                continue;
            }
            // p[i] != p[len]
            if (len != 0) {
                // step back
                len = lps[len - 1];     // maybe I can step back and find a lps without starting from 0 again
            } else {
                lps[i] = 0;             // I give up. It's 0 indeed
                i++;
            }
        }
        return lps;
    }

    public int search(String s) {
        int i = 0, j = 0;
        while (i < s.length()) {
            if (s.charAt(i) == p.charAt(j)) {
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
            if (j == p.length()) {
                // found it
                return i - j;
            }
        }
        return -1;
    }
}
