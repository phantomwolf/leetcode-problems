package main;

class BfsSolution {
    // BFS
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // In degree
        int[] indegrees = new int[numCourses];
        // Build graph
        List<Integer>[] graph = new LinkedList[numCourses];
        for (int v = 0; v < numCourses; v++) {
            graph[v] = new LinkedList<>();
        }
        // Add edges
        for (int[] pre : prerequisites) {
            int from = pre[1];
            int to = pre[0];
            graph[from].add(to);
            indegrees[to]++;
        }
        // BFS
        Queue<Integer> q = new LinkedList<>();
        // Enqueue all vertice with 0 in-degree
        for (int v = 0; v < numCourses; v++) {
            if (indegrees[v] == 0) {
                q.add(v);
            }
        }
        int count = 0; // How many vertice have been visited?
        while (!q.isEmpty()) {
            int v = q.poll();
            count++;
            // Reduce in-degrees of its neighbors
            for (int u : graph[v]) {
                indegrees[u]--;
                if (indegrees[u] == 0) {
                    // Vertex u has 0 in-degree now. No vertex depends on it. We can visit it now.
                    q.add(u);
                }
            }
        }
        if (count == numCourses) {
            // All vertice have been visited. No cycle.
            return true;
        }
        return false;
    }

}
