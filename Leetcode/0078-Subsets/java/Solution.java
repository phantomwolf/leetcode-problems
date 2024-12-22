class Solution {
    // path stores elements in the current subset
    private Stack<Integer> path = new Stack<>();

    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        backtrack(nums, 0, res);
        return res;
    }

    /**
     * nums: elements to choose from
     * start: choose next element from [start, nums.length)
     * res: result
     */
    void backtrack(int[] nums, int start, List<List<Integer>> res) {
        // pre-order traversal of tree
        res.add(new ArrayList<Integer>(path));  // empty set is also a valid result
        for (int i = start; i < nums.length; i++) {
            path.push(nums[i]);
            backtrack(nums, i + 1, res);
            path.pop();
        }
    }
}

