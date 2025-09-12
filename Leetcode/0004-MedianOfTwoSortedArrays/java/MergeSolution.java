public class MergeSolution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        // How many steps needed to reach the median(if odd) or first median(if even)
        int half = (m+n)%2 == 0 ? (m+n)/2-1 : (m+n)/2;

        int i = 0, j = 0;
        for (int k = 0; k < half; k++) {
            int num1 = (i < m) ? nums1[i] : Integer.MAX_VALUE;
            int num2 = (j < n) ? nums2[j] : Integer.MAX_VALUE;
            if (num1 < num2) {
                i++;
            } else {
                j++;
            }
        }
        int num1 = (i < m) ? nums1[i] : Integer.MAX_VALUE;
        int num2 = (j < n) ? nums2[j] : Integer.MAX_VALUE;
        int sum;
        if (num1 < num2) {
            i++;
            sum = num1;
        } else {
            j++;
            sum = num2;
        }

        // If odd
        if ((m+n)%2 != 0) {
            return sum;
        }
        // If even
        num1 = (i < m) ? nums1[i] : Integer.MAX_VALUE;
        num2 = (j < n) ? nums2[j] : Integer.MAX_VALUE;
        sum += Math.min(num1, num2);
        return sum/2.0;
    }
}