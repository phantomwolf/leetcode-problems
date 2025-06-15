public class Solution1 {
    public int[] topKFrequent(int[] nums, int k) {
        if (nums.length == 1) {
            return nums;
        }

        Map<Integer, Integer> count = new HashMap<>();
        for (int n : nums) {
            count.put(n, count.getOrDefault(n, 0)+1);
        }
        List<Pair<Integer, Integer>> pairs = new ArrayList<>();
        for (Map.Entry<Integer, Integer> e : count.entrySet()) {
            pairs.add(new Pair<Integer, Integer>(e.getValue(), e.getKey()));
        }
        // Quick select
        int left = 0, right = pairs.size()-1;
        int target = pairs.size()-k;     // the index we're looking for
        while (true) {
            int pivot = partition(pairs, left, right);
            if (pivot == target) {
                break;
            }
            if (pivot < target) {
                left = pivot+1;
            } else {
                right=pivot-1;
            }
        }
        // Collect result
        int[] result = new int[pairs.size()-target];
        for (int i = 0; i < result.length; i++) {
            result[i] = pairs.get(i+target).getValue();
        }
        return result;
    }

    private int partition(List<Pair<Integer, Integer>> pairs, int left, int right) {
        Pair<Integer, Integer> pivot = pairs.get(left);
        int l = left+1, r = right;
        while (true) {
            while (l <= right && pairs.get(l).getKey() < pivot.getKey()) {
                l++;
            }
            while (r >= left && pairs.get(r).getKey() > pivot.getKey()) {
                r--;
            }
            if (l >= r) {
                swap(pairs, left, r);
                return r;
            }
            swap(pairs, l, r);
            l++;
            r--;
        }
    }

    private void swap(List<Pair<Integer, Integer>> pairs, int i, int j) {
        Pair<Integer, Integer> tmp = pairs.get(i);
        pairs.set(i, pairs.get(j));
        pairs.set(j, tmp);
    }
}