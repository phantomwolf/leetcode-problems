=========================================
Fisher–Yates shuffle及其变种
=========================================

算法的目标
================
算法的目标是将有个有限集中的元素洗牌，使得每次取出的数字都是随机的。可用于生成一个无重复数字的随机序列。

算法步骤
===============
伪代码::

    -- To shuffle an array a of n elements (indices 0..n-1):
    for i from n−1 downto 1 do
        j ← random integer such that 0 ≤ j ≤ i
        exchange a[j] and a[i]

一个等价的算法是，从相反的方向将数组洗牌::

    -- To shuffle an array a of n elements (indices 0..n-1):
    for i from 0 to n−2 do
        j ← random integer such that i ≤ j < n
        exchange a[i] and a[j]

inside-out算法
===================
将数组复制一份，同时进行洗牌::

    -- To initialize an array a of n elements to a randomly shuffled copy of source, both 0-based:
    for i from 0 to n − 1 do
        j ← random integer such that 0 ≤ j ≤ i
        if j ≠ i
            a[i] ← a[j]
        a[j] ← source[i]

当不知道source的长度时::

    -- To initialize an empty array a to a randomly shuffled copy of source whose length is not known:
    while source.moreDataAvailable
        j ← random integer such that 0 ≤ j ≤ a.length
        if j = a.length
            a.append(source.next)
        else
            a.append(a[j])
            a[j] ← source.next
