class DfsSolution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // Create a HashMap
        List<Integer>[] edges = new LinkedList[numCourses];
        for (int i = 0; i < edges.length; i++) {
            edges[i] = new LinkedList<Integer>();
        }
        for (int[] pre : prerequisites) {
            int from = pre[1];
            int to = pre[0];
            edges[from].add(to);
        }
        boolean[] visited = new boolean[numCourses];
        boolean[] onPath = new boolean[numCourses];
        for (int n = 0; n < numCourses; n++) {
            if (canFinish(edges, n, visited, onPath) == false) {
                return false;
            }
        }
        return true;
    }

    private boolean canFinish(List<Integer>[] edges, int course, boolean[] visited, boolean[] onPath) {
        if (onPath[course]) {
            // Cycle detected
            return false;
        }
        if (visited[course]) {
            // Skip
            return true;
        }
        onPath[course] = true;
        visited[course] = true;
        // Post-order traversal
        List<Integer> edgeList = edges[course];
        for (int dependent : edgeList) {
            boolean ret = canFinish(edges, dependent, visited, onPath);
            if (ret == false) {
                // Cycle detected recursively
                return false;
            }
        }
        onPath[course] = false;
        return true;
    }
}