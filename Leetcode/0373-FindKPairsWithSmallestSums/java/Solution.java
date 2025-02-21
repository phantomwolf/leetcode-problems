class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        List<List<Integer>> res = new ArrayList<>();
        // Priority queue stores tuples: (sum, index1, index2). index1 is the element index of nums1
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        // De-duplicate
        HashSet<Pair<Integer, Integer>> visited = new HashSet<>();
        // Add first pair
        pq.add(new int[]{nums1[0] + nums2[0], 0, 0});
        visited.add(new Pair<Integer, Integer>(0, 0));
        while (res.size() < k) {
            int[] tuple = pq.remove();
            int p1 = tuple[1];
            int p2 = tuple[2];
            res.add(Arrays.asList(nums1[p1], nums2[p2]));
            // Proceed to next 2 possible pairs
            Pair<Integer, Integer> pair1 = new Pair<>(p1+1, p2);
            if (p1+1 < nums1.length && !visited.contains(pair1)) {
                pq.add(new int[]{nums1[p1+1] + nums2[p2], p1+1, p2});
                visited.add(pair1);
            }
            Pair<Integer, Integer> pair2 = new Pair<>(p1, p2+1);
            if (p2+1 < nums2.length && !visited.contains(pair2)) {
                pq.add(new int[]{nums1[p1]+nums2[p2+1], p1, p2+1});
                visited.add(pair2);
            }
        }
        return res;
    }
}