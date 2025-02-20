public class Solution3 {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        HashSet<Integer> edgeSet = new HashSet<>();
        for (int[] b : buildings) {
            int left = b[0];
            int right = b[1];
            edgeSet.add(left);
            edgeSet.add(right);
        }
        List<Integer> edges = new ArrayList<Integer>(edgeSet);
        Collections.sort(edges);

        List<List<Integer>> answer = new ArrayList();
        for (int edge : edges) {
            int maxHeight = 0;
            for (int[] b : buildings) {
                int left = b[0];
                int right = b[1];
                int height = b[2];
                // If current building intersects with the sweep line, update maxHeight
                if (left <= edge && edge < right) {
                    maxHeight = Math.max(maxHeight, height);
                }
            }
            // If [position, maxHeight] is the first key point,
            // or the height has changed,
            // add it to the answer
            if (answer.isEmpty() || answer.get(answer.size() - 1).get(1) != maxHeight) {
                answer.add(Arrays.asList(edge, maxHeight));
            }
        }
        return answer;
    }
}
