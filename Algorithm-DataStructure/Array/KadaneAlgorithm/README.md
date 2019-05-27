# 最大子数列问题
在计算机科学中，最大子数列问题的目标是在数列的一维方向找到一个连续的子数列，使该子数列的和最大。例如，对一个数列 −2, 1, −3, 4, −1, 2, 1, −5, 4，其连续子数列中和最大的是 4, −1, 2, 1, 其和为6。

该问题最初由布朗大学的Ulf Grenander教授于1977年提出，当初他为了展示数字图像中一个简单的最大似然估计模型。不久之后卡内基梅隆大学的Jay Kadane提出了该问题的线性算法。（Bentley 1984）。 

## Kadane算法
Kadane算法扫描一次整个数列的所有数值，在每一个扫描点计算以该点数值为结束点的子数列的最大和（正数和）。该子数列由两部分组成：以前一个位置为结束点的最大子数列、该位置的数值。因为该算法用到了“最佳子结构”（以每个位置为终点的最大子数列都是基于其前一位置的最大子数列计算得出），该算法可看成动态规划的一个例子。

算法可用如下Python代码实现：

```
def max_subarray(A):
    max_ending_here = max_so_far = A[0]
    for x in A[1:]:
        max_ending_here = max(x, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far
```

该问题的一个变种是：如果数列中含有负数元素，允许返回长度为零的子数列。在这些条件下，结果的最小值为0。该问题可用如下代码解决：

```
def max_subarray(A):
    max_ending_here = max_so_far = 0
    for x in A:
        max_ending_here = max(0, max_ending_here + x)
        max_so_far = max(max_so_far, max_ending_here)
    return max_so_far
```

这种算法稍作修改就可以记录最大子数列的起始位置。Kadane算法时间复杂度为O(n)，空间复杂度为O(1)

参见Leetcode 53
