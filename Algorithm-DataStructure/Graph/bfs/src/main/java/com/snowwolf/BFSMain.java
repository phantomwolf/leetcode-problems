package com.snowwolf;

import java.lang.*;

public class BFSMain {
    public static void main(String[] args) {
        int V = 13;
        int[][] edges = {
                {0, 5}, {0, 1}, {2, 0}, {2, 3}, {3, 5}, {3, 2}, {4, 3},
                {4, 2}, {5, 4}, {6, 9}, {6, 4}, {6, 0}, {7, 6}, {7, 8}, {8, 7},
                {8, 9}, {9, 11}, {9, 10}, {10, 12}, {11, 4}, {11, 12}, {12, 9},
        };
        DirectedGraph directedGraph = new DirectedGraph(V, edges);
        System.out.printf("Directed graph: %s\n", directedGraph);
        directedGraph.bfs();
        System.out.printf("BFS: %s\n", directedGraph.bfsResult);
        System.out.printf("Path to 12: %s\n", directedGraph.shortestPath(12));

        UndirectedGraph undirectedGraph = new UndirectedGraph(V, edges);
        System.out.printf("Undirected graph: %s\n", undirectedGraph);
        undirectedGraph.bfs();
        System.out.printf("BFS: %s\n", undirectedGraph.bfsResult);
        System.out.printf("Path to 12: %s\n", undirectedGraph.shortestPath(12));
    }
}
