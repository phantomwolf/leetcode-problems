class Solution {
    private String turnWheel(String input, int index, boolean forward) {
        char c = input.charAt(index);
        if (forward) {
            c = (c == '9') ? '0' : (char)(c + 1);
        } else {
            c = (c == '0') ? '9' : (char)(c - 1);
        }
        StringBuilder sb = new StringBuilder(input);
        sb.setCharAt(index, c);
        return sb.toString();
    }

    public int openLock(String[] deadends, String target) {
        HashSet<String> visited = new HashSet<>(Arrays.asList(deadends));
        // Special case
        String start = "0000";
        if (visited.contains(start)) {
            return -1;
        }
        // 1. Create queue
        Queue<Pair<String, Integer>> queue = new LinkedList<>();
        // 2. Enqueue starting point
        queue.add(new Pair(start, 0));
        // 3. While queue is not empty, keep traversing
        while (!queue.isEmpty()) {
            // 4. Dequeue element
            Pair<String, Integer> pair = queue.remove();
            // 5. Check if target reached
            String wheel = pair.getKey();
            int turns = pair.getValue();
            if (wheel.equals(target)) {
                return turns;
            }
            // 6. Enqueue all its neighbors
            for (int i = 0; i < 4; i++) {
                String forward = turnWheel(wheel, i, true);
                if (!visited.contains(forward)) {
                    visited.add(forward);
                    queue.add(new Pair<>(forward, turns + 1));
                }
                String reverse = turnWheel(wheel, i, false);
                if (!visited.contains(reverse)) {
                    visited.add(reverse);
                    queue.add(new Pair<>(reverse, turns + 1));
                }
            }
        }
        return -1;
    }
}
