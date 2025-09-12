public class Solution1 {
    public boolean isPalindrome(String s) {
        // Corner case
        if (s.length() <= 1) {
            return true;
        }

        int i = 0, j = s.length()-1;
        while (i < j) {
            char c = s.charAt(i);
            if (!Character.isLetterOrDigit(c)) {
                i++;
                continue;
            }

            char d = s.charAt(j);
            if (!Character.isLetterOrDigit(d)) {
                j--;
                continue;
            }

            if (Character.toLowerCase(c) != Character.toLowerCase(d)) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
}
