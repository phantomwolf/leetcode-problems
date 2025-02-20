package com.snowwolf;

// Naive implementation without optimization
public class UnionFind {
    // parent[x] is the parent id of node x
    private int[] parent;

    // Number of connected components
    private int count;

    // n is the number of nodes
    public UnionFind(int n) {
        // At the beginning, nodes are not connected. Each node's parent is itself.
        this.parent = new int[n];
        for (int i = 0; i < n; i++) {
            this.parent[i] = i;
        }
        // Each node is a connected component
        this.count = n;
    }

    // Find the root node of the connected component where x resides in
    public int find(int x) {
        // while x isn't a root of a connected component
        while (parent[x] != x) {
            x = parent[x];
        }
        return x;
    }

    public boolean connected(int p, int q) {
        int rootP = this.find(p);
        int rootQ = this.find(q);
        return rootP == rootQ;
    }

    public void union(int p, int q) {
        int rootP = this.find(p);
        int rootQ = this.find(q);
        if (rootP == rootQ) {
            // Already connected
            return;
        }
        // Attach one tree to another
        parent[rootP] = rootQ;
        // Reduce number of connected components
        this.count--;
    }

    public int count() {
        return this.count;
    }
}
