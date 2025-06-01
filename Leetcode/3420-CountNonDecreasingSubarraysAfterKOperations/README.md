# 3420. Count Non-Decreasing Subarrays After K Operations
You are given an array nums of n integers and an integer k.

For each subarray of nums, you can apply up to k operations on it. In each operation, you increment any element of the subarray by 1.

Note that each subarray is considered independently, meaning changes made to one subarray do not persist to another.

Return the number of subarrays that you can make non-decreasing ​​​​​after performing at most k operations.

An array is said to be non-decreasing if each element is greater than or equal to its previous element, if it exists.

## Example 1:

Input: nums = [6,3,1,2,4,4], k = 7

Output: 17

Explanation:

Out of all 21 possible subarrays of nums, only the subarrays [6, 3, 1], [6, 3, 1, 2], [6, 3, 1, 2, 4] and [6, 3, 1, 2, 4, 4] cannot be made non-decreasing after applying up to k = 7 operations. Thus, the number of non-decreasing subarrays is 21 - 4 = 17.

## Example 2:

Input: nums = [6,3,1,3,6], k = 4

Output: 12

Explanation:

The subarray [3, 1, 3, 6] along with all subarrays of nums with three or fewer elements, except [6, 3, 1], can be made non-decreasing after k operations. There are 5 subarrays of a single element, 4 subarrays of two elements, and 2 subarrays of three elements except [6, 3, 1], so there are 1 + 5 + 4 + 2 = 12 subarrays that can be made non-decreasing.

## Constraints:

* 1 <= nums.length <= 105
* 1 <= nums[i] <= 109
* 1 <= k <= 109

# Solutions
We use example 1 to showcase the solutions:

    nums = [6,3,1,2,4,4], k = 7

## Brute force solution
We maintain a non-decreasing window. Each time, we add the next number to it. If adding the number to the window makes it decreasing, we add some value to the new number and subtract the value from k. If that makes k < 0, it's impossible to add this new number to the window and the scanning stops. Next time, we choose another starting index.

How do we know if adding a number to the window will make it decreasing(given we can't modify the array)? We use a variable to track the largest number in the window.

First, let's start from index 0:

1. Add nums[0] to window: window = [6], k = 7.
2. Largest number so far is 6. To add nums[1] to the window, add 6 - 3 = 3 to it and make the window non-decreasing: window = [6, 3], k = 7 - 3 = 4.
3. To add nums[2] to window, add 6 - 1 = 5 to it to make the window non-decreasing: window = [6, 3, 1] and k = 4 - 5 = -1. k < 0 indicates it's impossible to add nums[2] to the window. The longest window we can get is [6, 3].
4. By starting from index 0, we found 2 eligible subarrays: [6] and [6, 3]. 

Next, we start from index 1:

1. Add nums[1] = 3 to window: window = [3], k = 7.
2. Largest number so far is 3. Add nums[2] = 1 to window: window = [3, 1], k = 7 - (3 - 1) = 5.
3. Largest number so far is 3. Add nums[3] = 2 to window: window = [3, 1, 2], k = 5 - (3 - 2) = 4.
4. Add nums[4] = 4 to window won't make it decreasing: window = [3, 1, 2, 4], k = 4.
5. Add nums[5] = 4 to window won't make it decreasing: window = [3, 1, 2, 4, 4], k = 4.
6. The longest window we can get is [3, 1, 2, 4, 4], length = 6. So we add 6 to the result.

Repeat this until we start from the last index 5.

Now we've solved the problem. Time complexity: O(n^2). Space complexity: O(1).

## Naive sliding window solution
In the brute force solution, each time we reconstruct the window from beginning, which wastes the results we've calculated. Let's see if we can use the sliding window technique.

First of all, we need to reverse the array and convert the problem to counting non-increasing subarrays. This is necessary because, it's easier to shrink the sliding window this way. We'll explain this later.

To solve this problem, we maintain a sliding window with non-increasing numbers.

After reversing, nums = [4, 4, 2, 1, 3, 6], k = 7.

1. Add nums[0], nums[1], nums[2], nums[3] to window. Since they're in non-increasing order, there's no need to perform any operations on them: window = [4, 4, 2, 1], k = 7.
2. Since nums[4] = 3 > 1, adding it to the window will break the non-increasing requirement. We have to perform 2 operations on the last 2 numbers of the window, then add 3 to window: window = [4, 4, 3, 3, 3], k = 4.
3. Since nums[5] = 6 > 3, we need to perform operations on numbers in the window: window = [6, 6, 6, 6, 6, 6], k = 4 - (2 + 2 + 3 + 3 + 3) = -9
4. Since k < 0, we need to shrink the window. By comparing the sliding window with nums, we can see how much operations we've performed on each of the numbers:

    nums   = [4, 4, 2, 1, 3, 6]
    window = [6, 6, 6, 6, 6, 6]

When we shrink the window, we need to return the operations we've performed on the number back to k, until k >= 0.

1. Remove 4 from window: window = [6, 6, 6, 6, 6], k += 6 - 4, k = -7
2. Remove 4 from window: window = [6, 6, 6, 6], k += 6 - 4, k = -5
3. Remove 2 from window: window = [6, 6, 6], k += 6 - 2, k = -1
4. Remove 1 from window: window = [6, 6], k += 6 - 1, k = 4

