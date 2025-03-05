public class Solution2 {
    public String minRemoveToMakeValid(String s) {
        StringBuilder sb1 = new StringBuilder();
        int balance = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                if (balance == 0) {
                    // Ignore this ')'
                    continue;
                } else {
                    balance--;
                }
            }
            sb1.append(c);
        }
        if (balance == 0) {
            return sb1.toString();
        }
        // Remove rightmost extra "("
        StringBuilder sb2 = new StringBuilder();
        for (int i = sb1.length() - 1; i >= 0; i--) {
            char c = sb1.charAt(i);
            if (c == '(' && balance > 0) {
                balance--;
                continue;
            }
            sb2.append(c);
        }
        return sb2.reverse().toString();
    }
}
