class DfsSolution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // Build graph
        List<Integer>[] graph = new ArrayList[numCourses];
        for (int i = 0; i < numCourses; i++) {
            graph[i] = new ArrayList<Integer>();
        }
        // Add edges
        for (int[] pre : prerequisites) {
            int from = pre[0];
            int to = pre[1];
            // edge means "depends on"
            graph[from].add(to);
        }

        // Cycle detection
        boolean[] visited = new boolean[numCourses];
        boolean[] onPath = new boolean[numCourses];
        for (int node = 0; node < numCourses; node++) {
            if (hasCycle(graph, node, visited, onPath)) {
                // Cycle detected. Can not finish courses.
                return false;
            }
        }
        return true;
    }

    // DFS
    private boolean hasCycle(List<Integer>[] graph, int node, boolean[] visited, boolean[] onPath) {
        if (onPath[node]) {
            // Cycle detected
            return true;
        }
        if (visited[node]) {
            // Skip visited node
            return false;
        }
        visited[node] = true;
        onPath[node] = true;
        // Visit neighbors
        for (int neighbor : graph[node]) {
            boolean res = hasCycle(graph, neighbor, visited, onPath);
            if (res) {
                return true;
            }
        }
        onPath[node] = false;
        return false;
    }
}