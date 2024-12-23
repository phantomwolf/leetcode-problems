import java.util.Stack;

class Solution {
    private Stack<Integer> path;
    private List<List<Integer>> res;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        path = new Stack<>();
        res = new LinkedList<>();
        Arrays.sort(candidates);
        backtrack(candidates, target, 0, 0);
        return res;
    }

    /**
     * start: choose next tree node from [start, candidates.length)
     */
    private void backtrack(int[] candidates, int target, int start, int currSum) {
        if (currSum == target) {
            res.add(new LinkedList<>(path));
        }
        // Optimization 1: Since candidates only contain positive numbers,
        // subtrees only have larger results than target. So we can ignore them.
        if (currSum >= target) {
            return;
        }
        // Traverse subtrees
        for (int i = start; i < candidates.length; i++) {
            if (currSum + candidates[i] > target) {
                // Optimization 2: since candidates is sorted
                // and candidates[i+1] > candidates[i],
                // currSum + candidates[i+1] > currSum + candidates[i] > target
                break;
            }
            path.push(candidates[i]);
            // The start parameter for subtrees is i instead of i+1, because the same number
            // can be chosen unlimited number of times
            backtrack(candidates, target, i, currSum + candidates[i]);
            path.pop();
        }
    }
}
