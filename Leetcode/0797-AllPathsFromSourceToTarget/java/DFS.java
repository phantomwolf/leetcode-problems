class Solution {
    // result
    private List<List<Integer>> paths = new ArrayList<>();

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        dfs(graph, 0, graph.length - 1, new Stack<Integer>());
        return paths;
    }

    private void dfs(int[][] graph, int vertex, int target, Stack<Integer> path) {
        path.push(vertex);
        if (vertex == target) {
            // found a path
            paths.add(new ArrayList<Integer>(path));
            // Don't forget to step back since we're using a shared path object
            path.pop();
            return;
        }
        // dfs its neighbors
        for (int v : graph[vertex]) {
            dfs(graph, v, target, path);
        }
        // Don't forget to step back since we're using a shared path object
        path.pop();
    }
}
