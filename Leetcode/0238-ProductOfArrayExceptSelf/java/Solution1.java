public class Solution1 {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] answer = new int[n];
        // prefix[i] = nums[0] * nums[1] * ... * nums[i]
        int[] prefix = new int[n];
        prefix[0] = nums[0];
        // suffix[i] = nums[i] * nums[i+1] * ... * nums[n-1]
        int[] suffix = new int[n];
        suffix[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            int j = n - i - 1;
            prefix[i] = prefix[i - 1] * nums[i];
            suffix[j] = suffix[j + 1] * nums[j];
        }

        for (int i = 0; i < n; i++) {
            int pre = (i - 1 >= 0) ? prefix[i - 1] : 1;
            int suf = (i + 1 < n) ? suffix[i + 1] : 1;
            answer[i] = pre * suf;
        }
        return answer;
    }
}