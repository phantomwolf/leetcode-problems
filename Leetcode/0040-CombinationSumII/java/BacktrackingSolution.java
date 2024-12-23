class Solution {
    private Stack<Integer> path = new Stack<>(); // stores the candidates in the current combination
    private int sum = 0;                         // tracks the sum of all elements in path

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        List<List<Integer>> res = new ArrayList<>();
        backtrack(candidates, target, 0, res);
        return res;
    }

    private void backtrack(int[] candidates, int target, int start, List<List<Integer>> res) {
        if (sum == target) {
            res.add(new ArrayList<Integer>(path));
            return;
        }
        // Next unique element
        int i = start;
        while(i < candidates.length) {
            sum += candidates[i];
            if (sum > target) {
                // Optimization: since candidates is sorted, any element after candidates[i] will be larger, generating
                // a larger sum value(definitely larger than target). Thus, those combinations can be ignored. Exit the loop here.
                sum -= candidates[i];
                break;
            }
            path.add(candidates[i]);
            backtrack(candidates, target, i + 1, res);
            path.pop();
            sum -= candidates[i];
            // Proceed to next unique element
            i++;
            while (i < candidates.length && candidates[i] == candidates[i-1]) {
                i++;
            }
        }
    }
}

