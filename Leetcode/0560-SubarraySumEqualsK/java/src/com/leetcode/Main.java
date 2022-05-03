package com.leetcode;

import java.util.HashMap;
import java.util.Map;

// 计算数组的前缀和(prefix sum)，任意一个子数组的和都可以表示为：prefixSum[j] - prefix[i] == k, j >= i
// 于是问题变为找出满足prefixSum[j] - prefix[i] == k的(i, j)对的数量，不允许重复
class Solution {
    public int subarraySum(int[] nums, int k) {
        int[] prefixSum = new int[nums.length + 1];
        for (int i = 1; i <= nums.length; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
        // Find how many (i, j) pairs exist so that prefixSum[j] - prefix[i] == k
        int res = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < prefixSum.length; i++) {
            int target = prefixSum[i] - k;
            if (map.containsKey(target)) {
                res += map.get(target);
            }
            map.put(prefixSum[i], map.getOrDefault(prefixSum[i], 0) + 1);
        }
        return res;
    }
}

public class Main {
    public static void main(String[] args) {
    }
}
