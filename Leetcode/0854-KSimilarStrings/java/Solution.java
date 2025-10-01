class Solution {
    public int kSimilarity(String s1, String s2) {
        Set<String> visited = new HashSet<>();
        visited.add(s1);
        Queue<String> queue = new ArrayDeque<>();
        queue.add(s1);

        // BFS
        int k = 0;
        while(!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String source = queue.remove();
                if (source.equals(s2)) {
                    // Reached destination
                    return k;
                }

                // Neighbors
                for (String neighbor : neighbors(source, s2)) {
                    if (!visited.contains(neighbor)) {
                        visited.add(neighbor);
                        queue.add(neighbor);
                    }
                }
            }
            k++;
        }
        return -1;
    }

    private List<String> neighbors(String source, String target) {
        List<String> res = new ArrayList<>();

        // Find a mismatch character
        int i = 0;
        while (i < source.length()) {
            if (source.charAt(i) != target.charAt(i)) {
                break;
            }
            i++;
        }

        // Try all possibilities
        for (int j = i+1; j < source.length(); j++) {
            if (source.charAt(j) == target.charAt(i)) {
                res.add(swap(source, i, j));
            }
        }
        return res;
    }

    private String swap(String s, int i, int j) {
        StringBuilder sb = new StringBuilder(s);
        char tmp = s.charAt(i);
        sb.setCharAt(i, s.charAt(j));
        sb.setCharAt(j, tmp);
        return sb.toString();
    }
}