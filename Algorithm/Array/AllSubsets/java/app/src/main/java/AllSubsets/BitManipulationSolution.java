package AllSubsets;

import java.util.ArrayList;
import java.util.List;

public class BitManipulationSolution {
    public List<List<Integer>> subsets;
    public List<Integer> subsetSums;

    public BitManipulationSolution(int[] nums) {
        subsets = new ArrayList<>();
        subsetSums = new ArrayList<>();
        calculateSubsets(nums);
    }

    private void calculateSubsets(int[] nums) {
        for (int mask = 0; mask < (1 << nums.length); mask++) {
            List<Integer> subset = new ArrayList<>();
            int sum = 0;
            for (int j = 0; j < nums.length; j++) {
                if ((mask & (1 << j)) != 0) {
                    subset.add(nums[j]);
                    sum += nums[j];
                }
            }
            subsets.add(subset);
            subsetSums.add(sum);
        }
    }
}
