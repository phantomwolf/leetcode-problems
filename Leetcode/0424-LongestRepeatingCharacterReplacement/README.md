# 424. Longest Repeating Character Replacement
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.

Constraints:

* 1 <= s.length <= 105
* s consists of only uppercase English letters.
* 0 <= k <= s.length

## Solution: sliding window
To solve this problem, we need to find a sliding window `[left, right)`. Inside the window, the most frequent char is `c` and and its amount is `freq[c]`, which means there're `right-left-freq[c]` other chars. If `k >= right-left-freq[c]`, we can make at most k operations to change other chars to `c`, thus creating a valid substring that meets the requirements.

First, expand the window until it's not valid any more. While we record the amount of characters with map `freq[]`, use a variable `maxFreq` to track the greatest frequency. Now calculate the number of operations needed to make it a valid substring: `right-left-maxFreq`. If it's no greater than k, we've found a valid substring and it's time to update the result.

Keep expanding the window, until `right-left-maxFreq > k`. Usually the next step is shrinking the window to make it valid again, usually by increasing `left` index. However, this problem only ask for the length of the longest substring, aka the size of the longest window. So shrinking the window doesn't generate a better result. Instead of shrinking it, we can simply move the window towards the right.

When we move the window, we'll need to update values in `freq[]` to record amount of each char. But how do we update `maxFreq` to track the new maximum frequency? The answer is: we don't have to. Since the size of the sliding window never shrinks, a smaller value of `maxFreq` will only generate a worse result, as `right-left-maxFreq` will increase and require more operations. We only need to update `maxFreq` when a new `freq[c] > maxFreq`.
