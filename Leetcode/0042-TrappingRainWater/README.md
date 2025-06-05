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
Suppose the length of height array is n. For i ∈ [0, n), the amount of rain stored at location i depends on the max height on its left side, and the max height on its right side:

    rain = min(
        max(height[0], height[1], ..., height[i-1]),
        max(height[i+1], height[i+2] ... height[n-1])
    ) - height[i]

If `rain <= 0`, the amount of rain stored at location i is 0. Sum values of all locations to get the overall result.

## Solution 1: using 2 arrays to record the max value on its left/right
To quickly know the max height on the left/right side of any location, we create 2 arrays leftMax[] and rightMax[] to store such values. Define:

* `leftMax[i] = max(leftMax[i-1], height[i])` is the max height in range height[0, i]. i is included.
* `rightMax[i] = max(rightMax[i+1], height[i])` is the max height in range height[i, n). i is included.

Base cases: `leftMax[0] = height[0]` and `rightMax[n-1] = height[n-1]`.

The rain stored at location i will be either `min(leftMax[i-1], rightMax[i+1]) - height[i]` or 0, whichever is greater:

    rain = max(
        0,          // if height[i] is greater than min(leftMax[i-1], rightMax[i+1]), no rain can be trapped at location i
        min(leftMax[i-1], rightMax[i+1]) - height[i]
    )

Time complexity: O(n). leftMax[], rightMax[] and result can be calculated by iterating the height[] array.
Space complexity: O(n).

## Solution 2: modified solution 1
The transition equation in solution 1 can be simplified. The rain stored at location i is:

    rain = min(leftMax[i], rightMax[i]) - height[i]

The above equation covers the two cases in solution 1. Explanation:

* when height[i] is smaller than `min(leftMax[i-1], rightMax[i+1])`, `height[i] != min(leftMax[i], rightMax[i])`, the equation is the same as solution 1
* when height[i] is greater than `min(leftMax[i-1], rightMax[i+1])`, we'll have `height[i] == min(leftMax[i], rightMax[i])`. the equation's value will be 0, which is the same as solution 1.

## Solution 3: two pointers
In previous solutions, we can see the rain trapped at location i is only related to the smaller one between `leftMax[i]` and `rightMax[i]`. This means if we know `leftMax[i] > rightMax[i]`, we don't even have to calculate the actual value of `leftMax[i]`.

Algorithm:

1. Introduce two indexes: `left = 0, right = n-1`. Use two variables to represent leftMax[] and rightMax[]: `lmax = 0` and `rmax = 0`.
2. Calculate `lmax = max(lmax, height[left]), rmax = max(rmax, height[right])`. The following is true: `lmax == leftMax[left]` and `rmax == rightMax[right]`.
3. Compare lmax and rmax:
    a. When `lmax < rmax`: according to definition, `left < right` and `rightMax[left] >= rightMax[right]`. If `lmax < rmax` is true, `lmax == leftMax[left] < rmax == rightMax[right] <= rightMax[left]`, aka `leftMax[left] < rightMax[left]`. So `min(leftMax[left], rightMax[left]) == leftMax[left] == lmax`. Rain trapped at location `left` is `lmax - height[left]`.
    b. When `lmax > rmax`: according to definition, `left < right` and `leftMax[left] <= leftMax[right]`. If `lmax > rmax` is true, `leftMax[right] >= lmax == leftMax[left] > rmax == rightMax[right]`, aka `leftMax[right] > rightMax[right]`. So `min(leftMax[right], rightMax[right]) == rightMax[right] == rmax`. Rain trapped at location `right` is `rmax - height[right]`.
    c. When `lmax == rmax`: both `lmax <= rightMax[left]` and `rmax <= leftMax[right]` are true. To make it simple, we can either calculate `left` or `right`.
4. After calculating rain trapped at location `left` or `right`, move the index towards the middle, until they meet.
