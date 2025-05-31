# 740. Delete and Earn
You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

* Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.

Return the maximum number of points you can earn by applying the above operation some number of times.

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.

Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.

Constraints:

* 1 <= nums.length <= 2 * 104
* 1 <= nums[i] <= 104

## Solution 1: Dynamic Programming
In the input array, there's no way to know how many points we can get if we delete a number. So we need to perform counting sort and convert it to an array points[i], where i is the num to delete and points[i] is the points we can get by deleting it.

Define dp[i] as the max points we can earn from points[i, n). For number `i`, we have two choices:

* Delete number `i`: this way we can't delete `i+1` anymore, so the points we get will be `points[i] + dp[i+2]`
* Don't delete number `i`: the points we can earn will be the same as those from points[i+1, n], aka `dp[i+1]`

Base cases:

* When there's only 1 number, we can get points[n-1]
* When there're 2 numbers to delete, it's either points[n-1] or points[n-2]

## Solution 2: Space-optimized Dynamic Programming
In solution 1, dp[i] only relies on dp[i+1] and dp[i+2]. We can use 3 variables to replace the dp[] array.