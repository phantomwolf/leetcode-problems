package AllSubsets;

import java.util.ArrayList;
import java.util.List;

public class BacktrackingSolution {
    public List<List<Integer>> subsets;
    public List<Integer> subsetSums;

    public BacktrackingSolution(int[] nums) {
        subsets = new ArrayList<>();
        subsetSums = new ArrayList<>();
        findSubsets(nums, 0, new ArrayList<>(), 0);
    }

    private void findSubsets(int[] nums, int index, List<Integer> subset, int sum) {
        // base case
        if (index == nums.length) {
            subsets.add(subset);
            subsetSums.add(sum);
            return;
        }
        // Choice 1: don't add nums[index] to the subset
        findSubsets(nums, index + 1, new ArrayList<>(subset), sum);
        // Choice 2: add nums[index] to the subset
        subset.add(nums[index]);
        sum += nums[index];
        findSubsets(nums, index + 1, new ArrayList<>(subset), sum);
    }
}
