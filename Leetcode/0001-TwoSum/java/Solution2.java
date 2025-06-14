public class Solution2 {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            // Use getOrDefault() method, so that only 1 query is needed
            int j = map.getOrDefault(target - nums[i], -1);
            if (j != -1) {
                return new int[] { i, j };
            }
            map.put(nums[i], i);
        }
        return new int[] { -1, -1 };
    }
}