public class Solution1 {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int search = target - nums[i];
            // 2 queries needed: first, containsKey() checks if the value exists in the hash
            // map; second, get() actually retrieves the value
            if (map.containsKey(search)) {
                return new int[] { i, map.get(search) };
            }
            map.put(nums[i], i);
        }
        return new int[] { -1, -1 };
    }
}