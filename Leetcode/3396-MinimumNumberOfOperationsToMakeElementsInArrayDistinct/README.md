# 3396. Minimum Number of Operations to Make Elements in Array Distinct
You are given an integer array nums. You need to ensure that the elements in the array are distinct. To achieve this, you can perform the following operation any number of times:

* Remove 3 elements from the beginning of the array. If the array has fewer than 3 elements, remove all remaining elements.

Note that an empty array is considered to have distinct elements. Return the minimum number of operations needed to make the elements in the array distinct.

Example 1:

Input: nums = [1,2,3,4,2,3,3,5,7]

Output: 2

Explanation:

* In the first operation, the first 3 elements are removed, resulting in the array [4, 2, 3, 3, 5, 7].
* In the second operation, the next 3 elements are removed, resulting in the array [3, 5, 7], which has distinct elements.

Therefore, the answer is 2.

Example 2:

Input: nums = [4,5,6,4,4]

Output: 2

Explanation:

* In the first operation, the first 3 elements are removed, resulting in the array [4, 4].
* In the second operation, all remaining elements are removed, resulting in an empty array.

Therefore, the answer is 2.

Example 3:

Input: nums = [6,7,8,9]

Output: 0

Explanation:

The array already contains distinct elements. Therefore, the answer is 0.

Constraints:

* 1 <= nums.length <= 100
* 1 <= nums[i] <= 100

## Solution 1: Sliding window
This problem is like a sliding window. Initially, we expand the sliding window to the entire array, recording number of each element and number of elements which have duplicates. As we remove elements from the array, we shrink the window. How do we quickly figure out if all elements are distinct as we shrink the window? This can be done by a `count[]` array and a variable `duplicates`:

* `count[]` stores the number of each element in the current window. Since `1 <= nums[i] <= 100`, its size is only 101.
* `duplicates` stores how many elements have duplicates in the current window

Algorithm:

First, we expand the sliding window. For each char, let `count[char]++`. If `count[char] >= 2`, it means char has duplicates and we increment variable `duplicates` to record the amount of elements that have duplicates.

Then, we shrink the window, each time by 3 elements(or when we reach the end). When a char is removed from the window, let `count[char]--`. If `count[char] <= 1`, it means char no longer has duplicates, thus let `duplicates--`. When `duplicates` reaches 0, no elements in the window has duplicates now and all elements are distinct.

Similar problem:

* 3. Longest Substring Without Repeating Characters
* 438. Find All Anagrams in a String
* 567. Permutation in String
* 76. Minimum Window Substring

## Solution 2: Reverse scanning
Since we can only remove elements from the left, in the end all distinct elements will be on the right side. So we can scan the array from right to left, recording chars we've seen. Once any duplicate is found, stop the scanning immediately and calculate the number of operations based on the length.

Suppose nums[i] is duplicated with another element on its right, then we need to remove range [0, i] to achieve distinctiveness. Each time we can only remove 3 elements, so we need to do `math.Ceil((i+1)/3)` operations.