Distinct
=====================================================
Compute number of distinct values in an array.

Description
----------------------------------------------
Write a function

    int solution(vector<int> &A);

that, given a zero-indexed array A consisting of N integers, returns the number of distinct values in array A.

Assume that:

        N is an integer within the range [0..100,000];
        each element of array A is an integer within the range [−1,000,000..1,000,000].

For example, given array A consisting of six elements such that:
 A[0] = 2    A[1] = 1    A[2] = 1
 A[3] = 2    A[4] = 3    A[5] = 1

the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.

Complexity:

        expected worst-case time complexity is O(N*log(N));
        expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).

Elements of input arrays can be modified.


解答
----------------------------------------------
统计数组中独一无二的元素，返回这些元素的数量。本题当然可以用set数据结构来解决，时间复杂度O(N)，空间复杂度O(N)，不过这里题目要求我们用排序。将数组排序后，顺序扫描数组，比较相邻的元素即可。若相邻的2个元素不相等，说明多了一个新的元素。
