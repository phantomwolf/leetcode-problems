package com.snowwolf;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class UndirectedGraph {
    List<Integer>[] adj;

    // Number of vertice
    int V;
    // Number of edges
    int E;

    // Record the previous vertex of each vertex
    int[] edgeTo;

    List<Integer> dfsResult;

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

    public void dfs() {
        dfsResult = new ArrayList<>();

        boolean[] visited = new boolean[V];
        for (int v = 0; v < V; v++) {
            if (!visited[v]) {
                edgeTo[v] = -1;
                dfs(v, visited);
            }
        }
    }

    private void dfs(int v, boolean[] visited) {
        dfsResult.add(v);

        visited[v] = true;
        for (int w : adj[v]) {
            if (!visited[w]) {
                edgeTo[w] = v;
                dfs(w, visited);
            }
        }
    }

    // Return the DFS path from a starting point to a vertex
    public List<Integer> path(int to) {
        List<Integer> p = new ArrayList<>();
        for (int v = to; v != -1; v = edgeTo[v]) {
            p.add(v);
        }
        Collections.reverse(p);
        return p;
    }
}
