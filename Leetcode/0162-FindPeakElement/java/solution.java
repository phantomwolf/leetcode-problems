class Solution {
    public int findPeakElement(int[] nums) {
        // Corner case
        if (nums.length == 1) {
            return 0;
        }

        // Binary search
        int left = 0, right = nums.length-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int prev = (mid-1 >= 0) ? nums[mid-1] : Integer.MIN_VALUE;
            int next = (mid+1 < nums.length) ? nums[mid+1] : Integer.MIN_VALUE;
            if (nums[mid] > prev && nums[mid] > next) {
                // Found peak
                return mid;
            }
            if (prev > nums[mid]) {
                // Continue searching on the left
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return -1;
    }
}
