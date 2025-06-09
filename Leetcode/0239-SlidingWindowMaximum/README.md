# 239. Sliding Window Maximum
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 

    Window position                Max
    ---------------               -----
    [1  3  -1] -3  5  3  6  7       3
     1 [3  -1  -3] 5  3  6  7       3
     1  3 [-1  -3  5] 3  6  7       5
     1  3  -1 [-3  5  3] 6  7       5
     1  3  -1  -3 [5  3  6] 7       6
     1  3  -1  -3  5 [3  6  7]      7

Example 2:

Input: nums = [1], k = 1
Output: [1]

Constraints:

* 1 <= nums.length <= 105
* -104 <= nums[i] <= 104
* 1 <= k <= nums.length

## Explanation
Given a sliding window of size k, we need to quickly know the max number within it, and add that number to the result.

## Solution 1: naive sliding window
Create sliding window [i, j] of size k. Iterate the window to find the max number within it, and add to result.

Move the window to the right by 1 position, and iterate the window again to find the max number within it. There're `n - k + 1` windows, and `k` elements inside each window.

Time complexity: O(nk). Space complexity: O(1).

## Solution 2: priority queue
We can use a priority queue. First, push all numbers of sliding window into the priority queue. The max number can be retrieved by peeking its top.

Then, we move the sliding window to the right by 1 position, and push the new number into the priority queue as well. By peeking its top, again we can know the max number in the sliding window.

But as the sliding window moves, some elements will be outside the sliding window. How do we remove them from the priority queue? Usually we don't directly remove elements from priority queue. Instead, we ignore them when they're on top. How do we know which elements should be ignored? When pushing elements, we push their index together with their value into the priority queue.

Time complexity: O(nlog(n)). Space complexity: O(n).

## Solution 3: monotonic queue
In a sliding window, the elements that come **before** the largest element will never be selected as the largest element of any future windows. For example, consider a window `[1, 2, 3, 4, 1]`. Because the window is sliding left to right, any window with the first three elements 1, 2, and 3 would also have the 4. So 1, 2, 3 will never be selected, because 4 exists.

However, we cannot ignore the items that follow the largest element. If the window keeps sliding, eventually 4 will be removed from the window, and 1 could be selected if no element is greater than it. For example, consider the following input: `[1, 2, 3, 4, 1,] 0, 0, 0, 0`. After sliding, it eventually will be `1, 2, 3, 4, [1, 0, 0, 0, 0]`

Again, if there's a greater element later, the smaller elements before it need to be ignored as well. For example, `[1, 2, 3, 4, 1,] 0, 0, 3` will eventually be `1, 2, 3, [4, 1, 0, 0, 3]`. Elements between 4 and 3 will be ignored, as they'll never be selected.

To effectively discard elements before the largest one, we can use a monotonic deque:

* Remove the front element if it's already outside the sliding window.
* Before pushing new element to the back, remove the back elements if they're smaller than the new one.
* The front element is the greatest inside the sliding window.

