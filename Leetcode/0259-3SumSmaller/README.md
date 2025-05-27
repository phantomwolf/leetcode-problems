# 259. 3Sum Smaller
Given an array of n integers nums and an integer target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.

Example 1:

Input: nums = [-2,0,1,3], target = 2
Output: 2
Explanation: Because there are two triplets which sums are less than 2:
    [-2,0,1]
    [-2,0,3]

Example 2:

Input: nums = [], target = 0
Output: 0

Example 3:

Input: nums = [0], target = 0
Output: 0

Constraints:

* n == nums.length
* 0 <= n <= 3500
* -100 <= nums[i] <= 100
* -100 <= target <= 100

## Solution 1
First, simialr to 3Sum: sort the input array, fix index `i`, and let `j` and `k` move from both sides to the middle.

Let `sum = nums[i]+nums[j]+nums[k]`, the key to the point is: what should we do when `sum > target`, `sum < target`, `sum == target`?

* When `sum >= target`, let `k--` so that we can get a smaller sum
* When `sum < target`, for any `m` in range `[j+1, k]`, `nums[i]+nums[j]+nums[m] < target`. We should collect results now: `result += k-j`. After collecting result, let `j++`.

Retrospective: Is it possible to miss any valid answers?

Consider the following situation. Initially `nums[i]+nums[j]+nums[k] >= target`, thus we let `k--` until `nums[i]+nums[j]+nums[k] < target`. At this moment, `nums[i]+nums[j]+nums[k]` is just smaller than target, meaning `nums[i]+nums[j]+nums[k+1] >= target`. Here we collect results `result += k-j`.

Next, let `j++` and continue. Notice that we didn't let `k` start over from `nums.size()-1` again. Will we miss any valid answers? In other words, if `nums[i]+nums[j]+nums[k]` is just smaller than target, aka `nums[i]+nums[j]+nums[k+1] >= target`, is it possible that `nums[i]+nums[j+1]+nums[k+1] < target`. The answer is definitely no, becuase `nums[i]+nums[j+1]+nums[k+1] > nums[i]+nums[j]+nums[k+1] >= target`. So after `j++`, there's no need to let `k` start from the rightmost index again: simply let `k` stay there.