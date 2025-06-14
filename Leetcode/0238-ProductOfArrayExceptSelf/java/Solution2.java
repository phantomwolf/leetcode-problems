class Solution2 {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        // Temporarily use answer[] as suffix[]
        int[] answer = new int[n];
        answer[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            answer[i] = answer[i + 1] * nums[i];
        }

        int prefix = 1;
        for (int i = 0; i < n; i++) {
            int suffix = (i + 1 < n) ? answer[i + 1] : 1;
            answer[i] = prefix * suffix;
            prefix *= nums[i];
        }
        return answer;
    }
}