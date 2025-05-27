# 快速排序
思路：每次从数组中选中一个数，作为pivot，将数组分区为两边，小于pivot的数放左边，大于pivot的数放右边。然后分别对左边和右边再次进行上述操作。

# 三种分区方法
Lomuto、Hoare和3-way partition(dutch flag problem). 一般来说最快的是Hoare，Hoare法比Lomuto法要减少很多交换次数，而且在拥有大量相同元素的情况下，也可以高效工作。

## Hoare
从左向右找到一个比pivot大的数，再从右向左找到一个比pivot小的数，将两者交换，继续上述操作直到两个下标相遇。

## Lomuto
从左向右找到一个比pivot小的数，将其交换到最左边，继续上述操作直到扫描完成。

## 3-way partition
三个下标：
* i: 小于mid的元素的写入位置
* j: 当前扫描位置
* k: 大于mid的元素的写入位置

循环不变式：
* [0, i)包含小于mid的值
* [i, j)包含等于mid的值
* [j, k]尚未处理好
* [k+1, arrLength)包含大于mid的值

```python
procedure three-way-partition(A : array of values, mid : value):
    i ← 0
    j ← 0
    k ← size of A - 1

    while j <= k:
        if A[j] < mid:
            swap A[i] and A[j]
            i ← i + 1
            j ← j + 1
        else if A[j] > mid:
            swap A[j] and A[k]
            k ← k - 1
        else:
            j ← j + 1
```
