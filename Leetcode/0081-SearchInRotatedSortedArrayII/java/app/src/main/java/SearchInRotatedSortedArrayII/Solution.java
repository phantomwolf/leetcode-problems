package SearchInRotatedSortedArrayII;

public class Solution {
    public boolean search(int[] nums, int target) {
        int lo = 0, hi = nums.length - 1;
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (nums[mi] == target) {
                return true;
            }
            if (nums[mi] == nums[lo] && nums[mi] == nums[hi]) {
                lo++;
                hi--;
            } else if (nums[mi] >= nums[lo]) {
                if (target >= nums[lo] && target < nums[mi])
                    hi = mi - 1;
                else
                    lo = mi + 1;
            } else {
                if (target >= nums[mi] && target <= nums[hi])
                    lo = mi + 1;
                else
                    hi = mi - 1;
            }
        }
        return false;
    }
}