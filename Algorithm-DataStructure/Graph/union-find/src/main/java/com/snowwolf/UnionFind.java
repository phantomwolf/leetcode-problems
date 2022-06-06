package com.snowwolf;

public class UnionFind {
    // IDs of connected components
    public int[] id;

    // Number of connected components
    int count;

    public UnionFind(int V) {
        count = V;
        id = new int[V];
        for (int i = 0; i < V; i++) {
            id[i] = i;
        }
    }

    // Returns the id of the connected component
    public int find(int v) {
        if (v != id[v])
            id[v] = find(id[v]);
        return id[v];
    }

    public boolean connected(int v, int w) {
        return find(v) == find(w);
    }

    // Connects 2 vertice if they're not connected already
    public void union(int v, int w) {
        int rootV = find(v);
        int rootW = find(w);
        // Do nothing if they're already connected
        if (rootV == rootW)
            return;
        id[rootV] = rootW;
        count--;
    }
}
