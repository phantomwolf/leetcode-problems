Missing Integer
========================================
Find the smallest positive integer that does not occur in a given sequence.

描述
-----------------------------
Write a function:

    int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

For another example, given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Assume that:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−1,000,000..1,000,000].

Complexity:

        expected worst-case time complexity is O(N);
        expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).

Elements of input arrays can be modified.


解答
-----------------------------
题目允许使用O(N)的空间，我们可以定义一个哈希表，将A中的元素全部存入。之后，再从1开始数到1,000,000，挨个探测数是否在哈希表中。第一个不存在与哈希表中的数，就是我们想要的结果。
