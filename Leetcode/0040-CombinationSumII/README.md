# 40. Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

## Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8

Output: 

```
[
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
]
```

## Example 2:

Input: candidates = [2,5,2,1,2], target = 5

Output: 

```
[
    [1,2,2],
    [5]
]
```

## Constraints:

* 1 <= candidates.length <= 100
* 1 <= candidates[i] <= 50
* 1 <= target <= 30

## Solution 1: backtracking
Although backtracking doesn't require the input array to be sorted, sorting it will benefit us from 2 ways:

* candidates[] may have duplicated numbers. After sorting, we can easily find the next unique element using a loop.
* After choosing candidates[i], if sum >= target, any unique element after candidates[i] will make sum > target (because candidates[] is sorted). Thus, we can simply ignore the elements after candidates[i].
