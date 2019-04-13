54. Spiral Matrix
=========================================
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following 2D array::

    [
        [ 1, 2, 3 ],
        [ 4, 5, 6 ],
        [ 7, 8, 9 ]
    ]

You should return::

    [1,2,3,6,9,8,7,4,5].

In other words, print the matrix in the following order::

    1   4 ← 7
    ↓   ↓   ↑
    2   5   8
    ↓       ↑
    3 → 6 → 9

解法
----------------------------
可用O(n)时间复杂度解除。设(x, y)为矩阵中的坐标，minX、maxX为x所能取的最小、最大值，minY、maxY为y所能取的最小、最大值。
