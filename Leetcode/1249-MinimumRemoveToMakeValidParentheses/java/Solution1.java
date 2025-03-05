public class Solution1 {
    public String minRemoveToMakeValid(String s) {
        HashSet<Integer> indexToRemove = new HashSet<>();
        // Store indexes of left parentheses
        Stack<Integer> stack = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == '(') {
                stack.push(i);
            } else if (c == ')') {
                if (stack.isEmpty()) {
                    indexToRemove.add(i);
                } else {
                    stack.pop();
                }
            }
        }
        while (!stack.isEmpty()) {
            indexToRemove.add(stack.pop());
        }
        // Generate result
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            if (indexToRemove.contains(i)) {
                continue;
            }
            sb.append(s.charAt(i));
        }
        return sb.toString();
    }
}