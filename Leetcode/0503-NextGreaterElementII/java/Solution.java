class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        Arrays.fill(res, -1);

        // Stores indexes of nums
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < 2*n; i++) {
            while (!stack.isEmpty() && nums[i%n] > nums[stack.peek()%n]) {
                res[stack.pop()%n] = nums[i%n];
            }
            stack.push(i%n);
        }
        return res;
    }
}