class SparseVector {
    public ArrayList<int[]> data = new ArrayList<>();

    SparseVector(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                data.add(new int[]{nums[i], i});
            }
        }
    }

	// Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {
        int res = 0;
        int i = 0;
        int j = 0;
        while (i < this.data.size() && j < vec.data.size()) {
            int[] pair1 = this.data.get(i);
            int num1 = pair1[0];
            int index1 = pair1[1];

            int[] pair2 = vec.data.get(j);
            int num2 = pair2[0];
            int index2 = pair2[1];

            if (index1 == index2) {
                res += num1 * num2;
                i++;
                j++;
            } else if (index1 < index2) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
}

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1 = new SparseVector(nums1);
// SparseVector v2 = new SparseVector(nums2);
// int ans = v1.dotProduct(v2);