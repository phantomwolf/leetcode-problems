package com.snowwolf;

import java.util.*;

public class UndirectedGraph {
    List<Integer>[] adj;

    // Number of vertice
    int V;
    // Number of edges
    int E;

    int[] edgeTo;

    List<Integer> bfsResult;

    public UndirectedGraph(int V) {
        this.V = V;
        adj = new LinkedList[V];
        for (int v = 0; v < V; v++) {
            adj[v] = new LinkedList<>();
        }
        edgeTo = new int[V];
    }

    public UndirectedGraph(int V, int edges[][]) {
        this(V);
        for (int[] edge : edges) {
            addEdge(edge[0], edge[1]);
        }
    }

    public void addEdge(int from, int to) {
        adj[from].add(to);
        adj[to].add(from);
        E++;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(String.format("%d:%s", 0, adj[0]));
        for (int v = 1; v < V; v++) {
            sb.append(String.format(", %d:%s", v, adj[v]));
        }
        return sb.toString();
    }

    public void bfs() {
        bfsResult = new ArrayList<>();

        boolean[] visited = new boolean[V];
        Queue<Integer> q = new ArrayDeque<>();
        for (int v = 0; v < V; v++) {
            if (!visited[v]) {
                edgeTo[v] = -1;
                bfs(v, visited, q);
            }
        }
    }

    // @param s     starting vertex
    public void bfs(int s, boolean[] visited, Queue<Integer> q) {
        // vertex should be marked as visited when it's added to the queue
        // otherwise, vertice will be repeatedly added to the queue
        visited[s] = true;
        q.add(s);
        while (!q.isEmpty()) {
            int v = q.remove();
            // logic for access the vertex
            bfsResult.add(v);
            // neighbors
            for (int w : adj[v]) {
                if (!visited[w]) {
                    // mark vertex as visited
                    visited[w] = true;
                    edgeTo[w] = v;
                    q.add(w);
                }
            }
        }
    }
    // Shortest path from starting point to a given vertex
    public List<Integer> shortestPath(int to) {
        List<Integer> path = new ArrayList<>();
        for (int v = to; v != -1; v = edgeTo[v]) {
            path.add(v);
        }
        Collections.reverse(path);
        return path;
    }
}
