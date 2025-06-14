# 11. Container With Most Water
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:

![question_11.jpg](question_11.jpg)

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:

Input: height = [1,1]
Output: 1

Constraints:

* n == height.length
* 2 <= n <= 105
* 0 <= height[i] <= 104

## Solution: two pointer
Given any two indexes `left` and `right`, `left < right`, the area will be: `(right - left) * min(height[left], height[right])`. Observations:

* If the heights stay the same, the greater `right - left` is, the greater the area will be.
* The smaller value between `height[left]` and `height[right]` will be the bottleneck.

Algorithm:

1. Let `left` and `right` start from both ends: `left = 0, right = height.size()-1`. This guarantees `(right - left)` will be the greatest. Calculate the area.
2. Compare `height[left]` and `height[right]` to see which is the bottleneck.
   1. When `height[left] < height[right]`, if we let `left++`, we may find a greater `height[left]` which makes area greater.
   2. When `height[left] > height[right]`, if we let `right--`, we may find a greater `height[right]` which makes area greater.
   3. When `height[left] = height[right]`, the only possibility of a greater area is moving both left and right to the middle. If we can find a greater height[left] and height[right], we may find a greater area.

