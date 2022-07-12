package MedianOfTwoSortedArrays;

public class BinarySearchSolution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int total = nums1.length + nums2.length;
        int half = total / 2;
        // swap 2 arrays if nums1 is longer than nums2
        if (nums1.length > nums2.length) {
            int[] tmp = nums2;
            nums2 = nums1;
            nums1 = tmp;
        }

        int l = 0, r = nums1.length - 1;
        while (true) {
            int m = (int) Math.floor((l + r) / 2.0);    // pivot for nums1
            int n = half - m - 2;   // pivot for nums2

            int left1 = (m >= 0) ? nums1[m] : Integer.MIN_VALUE;
            int right1 = (m + 1 < nums1.length) ? nums1[m + 1] : Integer.MAX_VALUE;
            int left2 = (n >= 0) ? nums2[n] : Integer.MIN_VALUE;
            int right2 = (n + 1 < nums2.length) ? nums2[n + 1] : Integer.MAX_VALUE;
            if (left1 <= right2 && left2 <= right1) {
                // found it
                if (total % 2 == 0) {
                    return (Math.max(left1, left2) + Math.min(right1, right2)) / 2.0;
                } else {
                    return Math.min(right1, right2);
                }
            } else if (left1 > right2) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
    }
}
