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

    public UndirectedGraph(int V) {
        this.V = V;
        adj = new LinkedList[V];
        for (int v = 0; v < V; v++) {
            adj[v] = new LinkedList<>();
        }
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

    // DFS
    public boolean isBipartite() {
        boolean[] visited = new boolean[V];
        boolean[] color = new boolean[V];
        for (int v = 0; v < V; v++) {
            if (!visited[v]) {
                if (!isBipartite(v, visited, color))
                    return false;
            }
        }
        return true;
    }

    private boolean isBipartite(int v, boolean[] visited, boolean[] color) {
        visited[v] = true;
        for (int w : adj[v]) {
            if (!visited[w]) {
                color[w] = !color[v];
                isBipartite(w, visited, color);
            } else if (color[v] == color[w]) {
                // 2 adjacent vertice have the same color
                return false;
            }
        }
        return true;
    }
}
