class Solution {
    public int combinationSum4(int[] nums, int target) {
        return dp(nums, target, new HashMap<Integer, Integer>());
    }

    /*
     * Calculates the possible combinations that sum up to target
     */
    private int dp(int[] nums, int target, HashMap<Integer, Integer> memo) {
        if (target == 0) {
            return 1;
        }
        if (memo.containsKey(target)) {
            return memo.get(target);
        }
        int res = 0;
        for (int i = 0; i < nums.length; i++) {
            int remain = target - nums[i];
            if (remain >= 0) {
                res += dp(nums, remain, memo);
            }
        }
        // Save to memo
        memo.put(target, res);
        return res;
    }
}
