package kthancestorofatreenode;

public class TreeAncestor {
    private int[][] lift;
    int maxPow;

    public TreeAncestor(int n, int[] parent) {
        maxPow = (int) Math.ceil(Math.log(n - 1) / Math.log(2));
        lift = new int[maxPow + 1][n];
        lift[0] = parent;
        for (int pow = 1; pow <= maxPow; pow++) {
            for (int i = 0; i < n; i++) {
                int prev = lift[pow - 1][i];
                lift[pow][i] = (prev == -1) ? -1 : lift[pow - 1][prev];
            }
        }
    }

    public int getKthAncestor(int node, int k) {
        int pow = maxPow;
        while (k > 0 && node != -1) {
            if (k >= (1 << pow)) {
                node = lift[pow][node];
                k -= 1 << pow;
            } else {
                pow--;
            }
        }
        return node;
    }
}
