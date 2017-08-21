MinPerimeterRectangle
====================================================
Find the minimal perimeter of any rectangle whose area equals N. 

Description
------------------------------------------
An integer N is given, representing the area of some rectangle.

The area of a rectangle whose sides are of length A and B is A * B, and the perimeter is 2 * (A + B).

The goal is to find the minimal perimeter of any rectangle whose area equals N. The sides of this rectangle should be only integers.

For example, given integer N = 30, rectangles of area 30 are::

        (1, 30), with a perimeter of 62,
        (2, 15), with a perimeter of 34,
        (3, 10), with a perimeter of 26,
        (5, 6), with a perimeter of 22.

Write a function::

    int solution(int N);

that, given an integer N, returns the minimal perimeter of any rectangle whose area is exactly equal to N.

For example, given an integer N = 30, the function should return 22, as explained above.

Assume that::

        N is an integer within the range [1..1,000,000,000].

Complexity::

        expected worst-case time complexity is O(sqrt(N));
        expected worst-case space complexity is O(1).

思路
------------------------------------------
一个矩阵，保持面积不变，什么时候它的两个边之和最小呢？当然是两个边的差最小的时候。

最理想的情况下，若sqrt(N)为整数，那么两个边都为sqrt(N)时，结果最小。

若sqrt(N)不是整数，我们取其下界，令一条边从sqrt(N)到1循环，若N能整除它，表明存在另一条整数边，使得面积为N。这时，两条边的差应该是最小的。
