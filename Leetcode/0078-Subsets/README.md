# 78. Subsets
Given an integer array nums of unique elements, return all possible subsets(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

## Example 1:
Input: nums = [1,2,3]

Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

## Example 2:
Input: nums = [0]

Output: [[],[0]]

## Constraints:

* 1 <= nums.length <= 10
* -10 <= nums[i] <= 10
* All the numbers of nums are unique.

## Solution
Obviously, backtrack technique should be used. A few tips:

* Empty set is also a valid result: there's no need to check if it's empty when adding to result
* The input array only contains unique elements: no need to sort and search for the next unique element
* The solution set must not contain duplicate subsets: each time we select the next element after the previous one, aka from [start, nums.length).

