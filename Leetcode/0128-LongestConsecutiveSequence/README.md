# 128. Longest Consecutive Sequence
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

Example 3:

Input: nums = [1,0,1,2]
Output: 3

Constraints:

* 0 <= nums.length <= 105
* -109 <= nums[i] <= 109

## Solution 1: brute force
In example 1, the longest consecutive elements sequence is [1, 2, 3, 4]. A naive way to calculate it is:

1. Iterate the input array. At some point, we'll meet number 1.
2. Search number 2 in the array. Found.
3. Search number 3 in the array. Found.
4. Search number 4 in the array. Found.
5. Search number 5 in the array. Not found. Thus the sequence starting from number 1 is [1, 2, 3, 4], and its length is 4.

For each number `num` we meet, we search for `num+1`, then `num+2`, `num+3`, until we can't find it.

With the brute force solution, we can do linear searches to find the next number(this can be optimized).

Time complexity: O(n^3). Space complexity: O(1).

## Solution 2: hash set
Solution 1 can be optimized in 2 ways:

First, we frequently search array to see if a number exists, which takes O(n) time. This can be optimized by adding all numbers into a hash set.

Second, for each number, we search for `number+1` inside the array. However, this is not always necessary. For example, if `number = 2`, we shouldn't start searching for 3 because `number-1 = 1` is also in the array: searching from `number = 1` will definitely generate a longer sequence. So we can check if `number-1` exists before searching: if yes, skip this number.

Remember the input array might contain duplicates. Once all numbers are added to the hash set, iterate the hash set instead of the input array.

Time complexity: O(n). This is because each sequence is only searched once.
Space complexity: O(n).

## Solution 3: sorting
In example 3, if we sort the input array, it will be [0,1,1,2]. Iterate the array:

1. First element is 0. In worst case, no elements are consecutive, and the sequence length will be 1. Let `length = 1` for now.
2. Second element is 1, which is `0 + 1`, meaning the elements are consecutive. Let `length = 2`.
3. Third element is still 1, which is the same as previous one. Ignore it.
4. Fourth element is 2, which is consecutive with second element. Let `length = 3`.

Now we've found a sequence with a length of 3. If we meet a non-consecutive element, simply let `length = 1`, meaning we've started a new sequence.
