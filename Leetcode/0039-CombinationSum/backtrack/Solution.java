import java.lang.*;
import java.util.*;

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> combinations = new ArrayList<List<Integer>>();
        Stack<Integer> path = new Stack<Integer>();
        Arrays.sort(candidates);

        path.push(0);
        int sum = candidates[0];
        while (!path.empty()) {
            while (sum < target) {
                Integer i = path.peek();
                path.push(i);
                sum += candidates[i];
            }
            if (sum == target) {
                List<Integer> combination = new ArrayList<Integer>();
                for (Integer i : path) {
                    combination.add(candidates[i]);
                }
                combinations.add(combination);
            }
            // Move backward and choose a different path
            Integer i = path.pop();
            sum -= candidates[i];
            while (!path.empty()) {
                i = path.pop();
                sum -= candidates[i];
                if (i < candidates.length-1) {
                    i++;
                    path.push(i);
                    sum += candidates[i];
                    break;
                }
            }
        }
        return combinations;
    }

    public static void main(String[] args) {
        int[] candidates = new int[]{2, 3, 5};
        int target = 8;
        Solution s = new Solution();
        List<List<Integer>> result = s.combinationSum(candidates, target);
        for (List<Integer> l : result) {
            System.out.printf("%d", l.get(0));
            for (int i=1; i < l.size(); i++) {
                System.out.printf("+ %d", l.get(i));
            }
            System.out.printf(" = %d\n", target);
        }
    }
}
