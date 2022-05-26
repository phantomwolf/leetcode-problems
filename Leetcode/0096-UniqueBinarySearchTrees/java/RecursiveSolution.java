class Solution {
    public int numTrees(int n) {
        return numTrees(1, n);
    }

    // How many unique trees can be build with numbers within [lo, hi]
    private int numTrees(int lo, int hi) {
        int result = 0;
        if (lo >= hi) {
            return 1;
        }
        for (int root = lo; root <= hi; root++) {
            result += numTrees(lo, root - 1) * numTrees(root + 1, hi);
        }
        return result;
    }
}
