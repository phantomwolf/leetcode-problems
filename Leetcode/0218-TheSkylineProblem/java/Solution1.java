public class Solution1 {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        // Use TreeSet to both sort and unify elements
        SortedSet<Integer> edgeSet = new TreeSet<>();
        for (int[] b : buildings) {
            int left = b[0];
            int right = b[1];
            edgeSet.add(left);
            edgeSet.add(right);
        }
        List<Integer> edges = new ArrayList<Integer>(edgeSet);
        // Hash table 'edgeIndexMap' record (position, index) pairs
        // index is the index of edges
        Map<Integer, Integer> edgeIndexMap = new HashMap<>();
        for (int i = 0; i < edges.size(); i++) {
            edgeIndexMap.put(edges.get(i), i);
        }
        // Initialize heights to record maximum height at each index
        int[] heights = new int[edges.size()];
        // Iterate over all the buildings
        for (int[] b : buildings) {
            // For each building, find its left and right index
            int left = b[0];
            int right = b[1];
            int height = b[2];
            int leftIndex = edgeIndexMap.get(left);
            int rightIndex = edgeIndexMap.get(right);
            // Update the max height within range [leftIndex, rightIndex)
            for (int i = leftIndex; i < rightIndex; i++) {
                heights[i] = Math.max(heights[i], height);
            }
        }
        // Collect results
        List<List<Integer>> answer = new ArrayList<>();
        // Iterate over heights
        for (int i = 0; i < heights.length; i++) {
            int currHeight = heights[i];
            int currPos = edges.get(i);
            // Add all the positions where the height changes to 'answer'.
            if (answer.isEmpty() || answer.get(answer.size() - 1).get(1) != currHeight) {
                answer.add(Arrays.asList(currPos, currHeight));
            }
        }
        return answer;
    }
}