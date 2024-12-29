package com.snowwolf;

import java.lang.*;

public class DFSMain {
    public static void main(String[] args) {
        int V = 13;
        int[][] edges = {
                {0, 5}, {0, 1}, {2, 0}, {2, 3}, {3, 5}, {3, 2}, {4, 3},
                {4, 2}, {5, 4}, {6, 9}, {6, 4}, {6, 0}, {7, 6}, {7, 8}, {8, 7},
                {8, 9}, {9, 11}, {9, 10}, {10, 12}, {11, 4}, {11, 12}, {12, 9},
        };
        DirectedGraph directedGraph = new DirectedGraph(V, edges);
        System.out.printf("Directed graph: %s\n", directedGraph);
        directedGraph.dfs();
        System.out.printf("DFS: %s\n", directedGraph.dfsResult);
        System.out.printf("Path to 2: %s\n", directedGraph.path(2));

        UndirectedGraph undirectedGraph = new UndirectedGraph(V, edges);
        System.out.printf("Undirected graph: %s\n", undirectedGraph);
        undirectedGraph.dfs();
        System.out.printf("DFS: %s\n", undirectedGraph.dfsResult);
        System.out.printf("Path to 2: %s\n", undirectedGraph.path(2));
    }
}
