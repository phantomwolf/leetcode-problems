# 75. Sort Colors
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

Constraints:

* n == nums.length
* 1 <= n <= 300
* nums[i] is either 0, 1, or 2.

Follow up: Could you come up with a one-pass algorithm using only constant extra space?

## Solution 1: couting sort(2 pass)
There're only 3 types of elements: 0, 1, 2. We can scan the input array and count the amount of each element with 3 variables. Then on the 2nd pass, we write these elements into the array.

## Solution 2: dutch national flag problem(1 pass)
Use 3 pointers to track locations:

1. p0 tracks the writing position of 0 elements
2. p2 tracks the writing location of 2 elements
3. curr tracks the scanning location

The algorithm:

1. Initialise the rightmost boundary of zeros: p0 = 0. During the algorithm execution nums[idx < p0] = 0.
2. Initialise the leftmost boundary of twos: p2 = n - 1. During the algorithm execution nums[idx > p2] = 2.
3. Initialise the index of the current element to consider: curr = 0.
4. While curr <= p2 :
    a. If nums[curr] = 0: swap currth and p0th elements and move both pointers to the right.
    b. If nums[curr] = 2: swap currth and p2th elements. Move pointer p2 to the left. Do NOT move curr because if the element swapped to curr is 0, we need to move it to p0 in the next iteration.
    c. If nums[curr] = 1: move pointer curr to the right.
