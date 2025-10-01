# 765. Couples Holding Hands
There are n couples sitting in 2n seats arranged in a row and want to hold hands.

The people and seats are represented by an integer array row where row[i] is the ID of the person sitting in the ith seat. The couples are numbered in order, the first couple being (0, 1), the second couple being (2, 3), and so on with the last couple being (2n - 2, 2n - 1).

Return the minimum number of swaps so that every couple is sitting side by side. A swap consists of choosing any two people, then they stand up and switch seats.

Example 1:

Input: row = [0,2,1,3]
Output: 1
Explanation: We only need to swap the second (row[1]) and third (row[2]) person.
Example 2:

Input: row = [3,2,0,1]
Output: 0
Explanation: All couples are already seated side by side.
 

Constraints:

* 2n == row.length
* 2 <= n <= 30
* n is even.
* 0 <= row[i] < 2n
* All the elements of row are unique.

## Solution 1: Greedy
This problem is a simplified version of [854. K-Similar Strings](../0854-KSimilarStrings/README.md). In 854 solution, when making a swap to change char 'a' to 'b', there're multiple possibilities. However in this problem, there's always only 1 possibility, because each person's couple is fixed.

We can simply linearly scan the `row[]` array, fix every pair of couple by making a swap. In the end, all couples will be fixed. We just need to record the number of swaps made.

For example, in example 1, `row = [0,2,1,3]`. For `row[0] = 0`, its couple should be `1`: we need to swap 1 with `row[1]`. But how do we know the index of value 1? We can scan `row[]` first to create a map from value to index.
