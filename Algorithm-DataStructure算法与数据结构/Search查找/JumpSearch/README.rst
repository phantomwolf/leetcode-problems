Jump Search
===============================================
本算法同样用于搜索有序数组。思路是，每次搜索跳过相同的距离m，将下列数与key对比::

    arr[0], arr[m], arr[2m] ... arr[km]

若key小于arr[km]，那么key肯定位于arr[(k-1)m]与arr[km]之间。接下来，线性搜索就可以了。

经过分析(http://www.geeksforgeeks.org/jump-search/)，最好的步进值为sqrt(n)，n为数组的长度。

本算法的时间复杂度为O(sqrt(n))，n为数组长度。
