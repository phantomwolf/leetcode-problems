MinAvgTwoSlice
=========================================
Find the minimal average of any slice containing at least two elements. 

Description
---------------------------------
A non-empty zero-indexed array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P < Q < N, is called a slice of array A (notice that the slice contains at least two elements). The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).

For example, array A such that:
    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8

contains the following example slices:

        slice (1, 2), whose average is (2 + 2) / 2 = 2;
        slice (3, 4), whose average is (5 + 1) / 2 = 3;
        slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.

The goal is to find the starting position of a slice whose average is minimal.

Write a function:

    int solution(vector<int> &A);

that, given a non-empty zero-indexed array A consisting of N integers, returns the starting position of the slice with the minimal average. If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.

For example, given array A such that:
    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8

the function should return 1, as explained above.

Assume that:

        N is an integer within the range [2..100,000];
        each element of array A is an integer within the range [−10,000..10,000].

Complexity:

        expected worst-case time complexity is O(N);
        expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).

Elements of input arrays can be modified.

解法
---------------------------------
这是一个数学问题，先说结论：由于题目限制切片最短长度为2，所以平均数最小的切片，长度必定为2或3。

证明：设数组A为[a, b, c, d, e, f, ...]，avg(P, Q)为切片(P, Q)的平均值。我们来看长度为4的切片(0, 3)，可知::

    avg(0, 3) = (a + b + c + d) / 4 = ((a + b) / 2 + (c + d) / 2) / 2 = (avg(0, 1) + avg(2, 3)) / 2

即avg(0, 3)等于avg(0, 1)与avg(2, 3)的平均数。若avg(0, 1)与avg(2, 3)相等，那么avg(0, 3)与两者也相等；若两者不相等，那么avg(0, 3)肯定大于两者中较小的那个。因此avg(0, 3)必然不会是我们要求的目标。

长度为5的切片(0, 4)也是一样的::

    avg(0, 4) = (a+b+c+d+e)/5 = (a+b+c)/5 + (d+e)/5 = (3/5) * (a+b+c)/3 + (2/5) * (d+e)/2
              = (3/5) * avg(0,2) + (2/5) * avg(3,4)
    即 5 * avg(0,4) = 3 * avg(0,2) + 2 * avg(3,4)

那么有没有可能是最小的切片平均数呢？我们不妨设avg(0,4) < avg(0,2)，且avg(0,4) < avg(3,4)，那么有::

    5 * avg(0,4) = 3 * avg(0,4) + 2 * avg(0,4) < 3 * avg(0,2) + 2 * avg(3,4)

这与之前的结论不符，因此avg(0,4)不可能同时比avg(0,2)和avg(3,4)都小。所以我们完全没必要求avg(0,4)，因为它不可能是最小的(至多和最小平均数相等)。

因此，求长度在3以上的切片平均数没有意义，问题转化为求长度为2、3的切片的平均数最小值。
