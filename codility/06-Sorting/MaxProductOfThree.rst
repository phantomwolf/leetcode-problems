MaxProductOfThree
==============================================
Maximize A[P] * A[Q] * A[R] for any triplet (P, Q, R).

Description
------------------------------------------
A non-empty zero-indexed array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:
  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6

contains the following example triplets:

        (0, 1, 2), product is −3 * 1 * 2 = −6
        (1, 2, 4), product is 1 * 2 * 5 = 10
        (2, 4, 5), product is 2 * 5 * 6 = 60

Your goal is to find the maximal product of any triplet.

Write a function:

    int solution(vector<int> &A);

that, given a non-empty zero-indexed array A, returns the value of the maximal product of any triplet.

For example, given array A such that:
  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6

the function should return 60, as the product of triplet (2, 4, 5) is maximal.

Assume that:

        N is an integer within the range [3..100,000];
        each element of array A is an integer within the range [−1,000..1,000].

Complexity:

        expected worst-case time complexity is O(N*log(N));
        expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).

Elements of input arrays can be modified.


解答
------------------------------------------
什么样的3个数，乘积最大呢？首先，乘积要为正数，这意味着3个数全部为正数，或者2个数为正数1个为负数；其次，这3个数的绝对值要大，这样乘积才能大。

首先，将数组增序排序，假设排序结果为[a, b, c, d, e, f, g]。那么，哪里有绝对值比较大的数呢？显然，要么在数组的开头(若它们为负数)，要么在末尾(若它们为正数)。观察后得知，乘积最大的3个数组合，只可能是2种情况：

1. 数组末尾最大的3个数(e, f, g)。这很容易理解，找出数组中最大的3个数相乘，普通情况下这就是最大值。
2. 数组末尾的1个数与数组开头的2个数，即(a, b, g)。当a与b为负数，且绝对值比e, f大时，(a, b, g)的乘积要比(e, f, g)大。

那么其它组合有没有可能呢？
