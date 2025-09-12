import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.stream.Collectors;

public class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        backtrack(nums, 0, path, res);
        return res;
    }

    private void backtrack(int[] nums, int i, List<Integer> path, List<List<Integer>> res) {
        // Base case
        if (i == nums.length) {
            res.add(path);
            return;
        }

        // option 1: include nums[i]
        List<Integer> newPath = new ArrayList<>(path);
        newPath.add(nums[i]);
        backtrack(nums, i+1, newPath, res);
        // option 2: don't include nums[i]
        backtrack(nums, i+1, path, res);
    }
}
