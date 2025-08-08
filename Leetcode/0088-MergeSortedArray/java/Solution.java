class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int j = m-1, k = n-1;
        for (int i = m+n-1; i >= 0; i--) {
            int v1 = (j >= 0) ? nums1[j] : Integer.MIN_VALUE;
            int v2 = (k >= 0) ? nums2[k] : Integer.MIN_VALUE;
            if (v1 > v2) {
                nums1[i] = v1;
                j--;
            } else {
                nums1[i] = v2;
                k--;
            }
        }
    }
}