package com.snowwolf;

public class UnionFindWithPathCompression {
    // parent[x] is the parent id of node x
   private int[] parent;

   // Number of connected components
   private int count;
   
    // n is the number of nodes
    public UnionFindWithPathCompression(int n) {
        // At the beginning, nodes are not connected. Each node's parent is itself.
        this.parent = new int[n];
        for (int i = 0; i < n; i++) {
           this.parent[i] = i;
        }
        // Each node is a connected component
        this.count = n;
    }

    // Find the root node of the connected component where x resides in
    // Added path compression
    public int find(int x) {
        if (parent[x] != x) {
            // While looking for the root node, 
            parent[x] = this.find(parent[x]);
        }
        return parent[x];
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
