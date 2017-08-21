Tape Equilibrium
==================================================
Minimize the value::

    |(A[0] + ... + A[P-1]) - (A[P] + ... + A[N-1])|.

描述
----------------------------------
A non-empty zero-indexed array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3

We can split this tape in four places:

        P = 1, difference = |3 − 10| = 7
        P = 2, difference = |4 − 9| = 5
        P = 3, difference = |6 − 7| = 1
        P = 4, difference = |10 − 3| = 7

Write a function:

    int solution(vector<int> &A);

that, given a non-empty zero-indexed array A of N integers, returns the minimal difference that can be achieved.

For example, given:
  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3

the function should return 1, as explained above.

Assume that:

        N is an integer within the range [2..100,000];
        each element of array A is an integer within the range [−1,000..1,000].

Complexity:

        expected worst-case time complexity is O(N);
        expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).

Elements of input arrays can be modified.

解法
----------------------------------
问题的关键在于，给定一个P的值，将数组分为两部分，如何快速求出两部分各自的和，以便求出两部分和的差的绝对值。

用常用的累积和方法就可以，准备一个数组sum，令sum[i] = A[0] + A[1] + A[2] + ... + A[i]。那么数组左右两部分的和分别为::

    A[0] + A[1] + ... + A[P-1] = sum[P-1]
    A[P] + A[P+1] + ... + A[N-1] = sum[N-1] - sum[P-1]

两部分和的差的绝对值为::

    | sum[N-1] - 2 * sum[P-1] |

有了快速计算两部分和的差的绝对值的方法，我们只需尝试所有可能的P，找出最小结果即可。
