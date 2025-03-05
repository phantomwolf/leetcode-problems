# 523. Continuous Subarray Sum
Given an integer array nums and an integer k, return true if nums has a good subarray or false otherwise.

A good subarray is a subarray where:

    its length is at least two, and
    the sum of the elements of the subarray is a multiple of k.

Note that:

    A subarray is a contiguous part of the array.
    An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.

Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.

Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.

Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false

Constraints:

* 1 <= nums.length <= 105
* 0 <= nums[i] <= 109
* 0 <= sum(nums[i]) <= 231 - 1
* 1 <= k <= 231 - 1

## Solution 1: Prefix Sum + Hash Map
First, let's build a prefix sum array for nums. Define `sum[i]` is the sum of `nums[0:i]`, inclusive. Now given any two indexes `i and j(i > j)`, we can calculate the sum of `nums[j:i]` immediately: `sum[i]-sum[j]`. So given any i, how do we find j(if any), so that `(sum[i] - sum[j]) % k = 0`? Let's dive into this problem.

Let `sum[i] % k = a, 0 <= a < k`, `sum[j] % k = b, 0 <= b < k`, then sum[i] and sum[j] can be written in the following forms(all variables are integers):

    sum[i] = x*k + a, x >= 0
    sum[j] = y*k + b, y >= 0

If `(sum[i] - sum[j]) % k = 0`, it means: `sum[i] - sum[j] = z * k`, z is an integer and z >= 0. The formula can be wrriten as:

    (x*k + a) - (y*k + b) = z * k
    a - b = (z - x + y) * k
    (a - b) % k = 0

Since `sum[i] % k = a, 0 <= a < k`, `sum[j] % k = b, 0 <= b < k`, there's only 1 possibility: a = b.

We can iterate the nums array, using variable currSum to track the sum of nums[0:i]. Now if we can find a previous sum value prevSum which makes `currSum % k = prevSum % k`, we've found a possible target subarray(need to make sure the subarray has a length of 2 or greater). Since we're comparing `currSum % k` and `prevSum % k`, we can just store each `currSum % k` into hash map. Since the problem requires the subarray to be 2 or longer, the value in the map can be the index `i(as if in sum[i])`.

```java
    for (int i = 0; i < nums.length; i++) {
        currSum += nums[i];
        if (!map.containsKey(currSum%k)) {
            map.put(sum, i);
            continue;
        }
        if (i - map.get(currSum%k) >= 2) {
            return true;
        }
    }
```

We're actually not interested in the sum of subarrays. Additionally, currSum might overflow. So we can just track the value of `currSum % k`.

```java
    for (int i = 0; i < nums.length; i++) {
        // currSum here is equal to currSum % k in the previous code example
        currSum = (currSum + nums[i]) % k;
        if (!map.containsKey(currSum)) {
            map.put(sum, i);
            continue;
        }
        if (i - map.get(currSum) >= 2) {
            return true;
        }
    }
```

Before this loop begins, don't forget to add a special key-value pair (0, -1): for empty subarray nums[0:-1], its sum is 0.
