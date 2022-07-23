# 42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:

    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:

    Input: height = [4,2,0,3,2,5]
    Output: 9

Constraints:

* n == height.length
* 1 <= n <= 2 * 104
* 0 <= height[i] <= 105

# Solution
Suppose the length of height array is N. For i ∈ [0, N), the amount of rain stored at location i depends on the max height on its left side, and the max height on its right side:

    result = min(
        max(height[0], height[1], ..., height[i]),
        max(height[i], height[i+1] ... height[N-1])
    ) - height[i]

If result is negative, result = 0. Sum results of all locations to get the overall result.

## Solution 1: using 2 arrays to record the max value on its left/right
To quickly know the max height on the left/right side of any location, we create 2 arrays leftMax[] and rightMax[] to store such values.

First, scan from left to right to create leftMax[]. Then scan from right to left to create rightMax[]. Once we have both arrays, the rain stored at each location is:

    min(leftMax[i], rightMax[i]) - height[i]

## Solution 2: 2 pointers
The rain water stored at location i solely depends on the smaller value of the left/right max value. There's no need to calculate leftMax[] and rightMax[] ahead.
