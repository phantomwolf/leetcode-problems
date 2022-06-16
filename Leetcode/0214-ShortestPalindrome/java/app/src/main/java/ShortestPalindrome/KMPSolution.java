package ShortestPalindrome;

public class KMPSolution {
    // lps[i] = the longest proper prefix of s[0..i] which is also a suffix of s[0..i]
    // Note: prefix/suffix must be a substring of s(s isn't a prefix/suffix of itself)
    private int[] buildLPS(String s) {
        int[] lps = new int[s.length()];
        // lps[0] is always 0 since a prefix/suffix must be a substring
        lps[0] = 0;
        // length of length of the previous longest prefix suffix
        int len = 0;
        // the loop calculates lps[i] for i = 1 to n-1
        int i = 1;
        while (i < s.length()) {
            if (s.charAt(i) == s.charAt(len)) {
                len++;
                lps[i] = len;
                i++;
                continue;
            }
            // s[i] != s[len]
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
        return lps;
    }

    public String shortestPalindrome(String s) {
        String r = new StringBuilder(s).reverse().toString();
        String c = String.format("%s#%s", s, r);
        int[] lps = buildLPS(c);
        int len = (lps[lps.length - 1] > s.length()) ? s.length() : lps[lps.length - 1];

        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= len; i--) {
            sb.append(s.charAt(i));
        }
        sb.append(s);
        return sb.toString();
    }
}
