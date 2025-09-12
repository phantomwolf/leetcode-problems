public class Solution1a {
    public boolean isMatch(String s, String p) {
        return dp(s, 0, p, 0);
    }

    // Returns true if s[i...] matches with p[j...]; otherwise returns false.
    // i and j are the indexes of string and pattern.
    private boolean dp(String s, int i, String p, int j) {
        // Base case: pattern exhausted
        if (j == p.length()) {
            return i == s.length();
        }
        // Base case: string exhausted
        if (i == s.length()) {
            if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
                // let 'p[j]*' match 0 characters and recursively check the rest
                return dp(s, i, p, j + 2);
            }
            return false;
        }

        if (s.charAt(i) == p.charAt(j) || p.charAt(j) == '.') {
            // s[i] and p[j] matches. Now check if p[j+1] is '*'
            if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
                // case 1: 'p[j]*' matches 0 characters. (x means any character)
                boolean cand1 = dp(s, i, p, j + 2);
                // case 2: * matches 1 or more characters(j didn't increment because 'p[j]*' can be
                // used again until it matches 0 characters)
                boolean cand2 = dp(s, i + 1, p, j);
                return cand1 || cand2;
            } else {
                // p[j+1] is not '*'. Just do a simple 1 character match.
                return dp(s, i + 1, p, j + 1);
            }
        } else {
            // s[i] and p[j] doesn't match. The only hope of matching is p[j+1] is '*', so
            // that it can match 0 characters.
            if (j + 1 < p.length() && p.charAt(j + 1) == '*') {
                return dp(s, i, p, j + 2);
            }
            // p[j+1] is not '*'. No hope of matching.
            return false;
        }
    }
}
