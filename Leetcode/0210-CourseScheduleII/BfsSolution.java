class BfsSolution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] result = new int[numCourses];
        // Build graph
        int[] indegree = new int[numCourses];
        List<Integer>[] graph = new LinkedList[numCourses];
        for (int v = 0; v < numCourses; v++) {
            graph[v] = new LinkedList<>();
        }
        // Add edges
        for (int[] pre : prerequisites) {
            int from = pre[1];
            int to = pre[0];
            graph[from].add(to);
            indegree[to]++;
        }
        // BFS
        int count = 0; // How many vertice have been visited?
        Queue<Integer> q = new LinkedList<>();
        // Add all vertice with 0 in-degree into queue
        for (int v = 0; v < numCourses; v++) {
            if (indegree[v] == 0) {
                q.add(v);
            }
        }
        while (!q.isEmpty()) {
            int v = q.poll();
            result[count] = v;
            count++;
            // Reduce the in-degree of its neighbors and enqueue if needed
            for (int u : graph[v]) {
                indegree[u]--;
                if (indegree[u] == 0) {
                    q.add(u);
                }
            }
        }
        if (count == numCourses) {
            return result;
        }
        return new int[0];
    }
}
