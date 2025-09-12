class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 0; i < nums.length-2; i = next(nums, i)) {
            int j = i+1, k = nums.length-1;
            while (j < k) {
                int sum = nums[i]+nums[j]+nums[k];
                if (sum == 0) {
                    res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    j = next(nums, j);
                    k = prev(nums, k);
                } else if (sum < 0) {
                    j = next(nums, j);
                } else {
                    k = prev(nums, k);
                }
            }
        }
        return res;
    }

    private int next(int[] nums, int i) {
        i++;
        while (i < nums.length && nums[i-1] == nums[i]) {
            i++;
        }
        return i;
    }

    private int prev(int[] nums, int i) {
        i--;
        while (i >= 0 && nums[i] == nums[i+1]) {
            i--;
        }
        return i;
    }
}