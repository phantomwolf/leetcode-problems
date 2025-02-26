# 53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

A subarray is a contiguous part of an array.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:

Input: nums = [1]
Output: 1

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23

Constraints:

* 1 <= nums.length <= 105
* -104 <= nums[i] <= 104

## Solution 1: Dynamic Programming
If we define dp[i] as the max sum of subarrays using numbers in nums[0, i], the problem will be complex, as we don't know where the subarray ends. So to make it simpler, we define dp[i] as:

    dp[i] is the max sum of subarrays which end at nums[i]

Base case: when i is 0, there's only 1 possible subarray {nums[0]}, so dp[0] = nums[0].

An subarray that ends at nums[i] has 2 possibilities:

1. an subarray which only contains nums[i]. Its max sum is: nums[i]
2. appending nums[i] to an subarray which ends at nums[i-1] to get a longer subarray. Its max sum is: dp[i-1] + nums[i]

Since dp[i] is the max of these two, dp[i] = max(nums[i], dp[i-1] + nums[i]).

```c++
    int maxSubArray(vector<int>& nums) {
        // Define dp[i] as the max sum of subarrays which ends with nums[i]
        vector<int> dp(nums.size());
        // Base case
        dp[0] = nums[0];
        int maxSum = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = std::max(dp[i-1] + nums[i], nums[i]);
            maxSum = std::max(dp[i], maxSum);
        }
        return maxSum;
    }
```

## Solution 2: Kadane's algorithm
Kadane's algorithm is basically a space optimized DP solution.

If you carefully examine the DP solution, the value of dp[i] only depends on dp[i-1]. This means we can use a single variable "maxSumEndingHere" to replace the dp[] array: `maxSumEndingHere = max(maxSumEndingHere + nums[i], nums[i])`

We'll still use a `maxSum` variable to track overall results: `maxSum = std::max(dp[i], maxSum)`

By doing this, we've discorvered the Kadane's algorithm.

```c++
    int maxSubArray(vector<int>& nums) {
        // Kadane's algorithm
        int maxSum = nums[0];
        int maxSumEndingHere = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxSumEndingHere = std::max(nums[i], maxSumEndingHere + nums[i]);
            maxSum = std::max(maxSumEndingHere, maxSum);
        }
        return maxSum;
    }
```
