class DfsSolution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        boolean[] visited = new boolean[numCourses];
        boolean[] onPath = new boolean[numCourses];
        List<Integer> result = new LinkedList<>();
        // Build graph
        List<Integer>[] graph = new LinkedList[numCourses];
        for (int v = 0; v < numCourses; v++) {
            graph[v] = new LinkedList<>();
        }
        for (int[] pre : prerequisites) {
            int from = pre[1];
            int to = pre[0];
            graph[from].add(to);
        }
        // Visit all vertice
        for (int v = 0; v < numCourses; v++) {
            boolean ret = topologicalSort(graph, v, visited, onPath, result);
            if (ret == false) {
                // Cycle detected
                return new int[] {};
            }
        }
        // Reverse list to get topological sort result
        Collections.reverse(result);
        return result.stream().mapToInt(Integer::intValue).toArray();
    }

    private boolean topologicalSort(List<Integer>[] graph, int v, boolean[] visited, boolean[] onPath,
            List<Integer> result) {
        if (onPath[v]) {
            // Cycle detected
            return false;
        }
        if (visited[v]) {
            // Skip
            return true;
        }
        onPath[v] = true;
        visited[v] = true;
        // Edges
        for (int u : graph[v]) {
            boolean ret = topologicalSort(graph, u, visited, onPath, result);
            if (ret == false) {
                // Cycle detected
                return false;
            }
        }
        // Post-order position
        onPath[v] = false;
        result.add(v);
        return true;
    }
}
