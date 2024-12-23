# 39. Combination Sum
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:

* All numbers (including target) will be positive integers.
* The solution set must not contain duplicate combinations.

## Example 1:
Input: candidates = [2,3,6,7], target = 7,

A solution set is:

```
[
  [7],
  [2,2,3]
]
```

## Example 2:
Input: candidates = [2,3,5], target = 8,

A solution set is:

```
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
```

## Solution 1: recursive backtrack
Backtrack can be used to find all possible combinations. Tips:

* Since we only want unique combinations, if we already included candidates[i] in the combination, candidates in range [0, i) shouldn't be used. Otherwise, there'll be duplicated combinations.
* Since the same number can be chosen unlimited times, if we already included candidates[i] in the combination, when choosing next element, candidates[i] shouldn't be exlucded from the choices. In other words, we should choose from [i, candidates.length) when choosing next element.

A few optimizations for this problem:

### Optimization 1
candiadates only contain positive numbers. Given:

* A = [a, b,..., c]
* sum(A) >= target
* B =  [a, b,..., c, d]

sum(B) will definitely be larger than target, thus combinations like B(combinations prefixed by A) can be ignored.

### Optimization 2
Sort candidates array in ascending order so that candiadates[i] < candiadates[i+1]. Given:

* A = [a, b,..., c, d]
* sum(A) >= target
* e is on the right side of d
* B = [a, b, ..., c, e]

sum(B) will definitely be larger than target, thus combinations like B(combinations prefixed by A) can be ignored.

## Iterative backtrack solution
使用backtrack法，尝试所有可能性。设candidates = [2, 3, 5]，target = 8

- 为避免出现重复的结果(例如[2, 3, 3]和[3, 2, 3])，当路径中已选择一个靠后的方向时，不应再选择靠前的方向。例如当路径中已选择3时，之后不应该再选择2
- 若提前将candidates排序，那么回退时，至少需要pop两次，push一次。例如若当前路径为[2, 2, 2, 2]，那么尝试[2, 2, 2, 3]是没有意义的，因为candidates是有序的，越靠后的candidate越大。2 + 2 + 2 + 2 >= 8，后退一步选一个后面的candidate是没有意义的。我们至少应该后退两步至[2, 2]，再继续前进。
