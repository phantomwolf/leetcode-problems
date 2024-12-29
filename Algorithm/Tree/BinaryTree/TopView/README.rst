Print Nodes in Top View of Binary Tree
======================================================
此题与Bottom View类似，不过变为找出各水平距离上，深度最浅的结点们。期望时间复杂度为O(n)。

A node x is there in output if x is the topmost node at its horizontal distance. Horizontal distance of left child of a node x is equal to horizontal distance of x minus 1, and that of right child is horizontal distance of x plus 1.

解答
------------------------------------------
类似Bottom View，对树进行level-order traversal，同时计算结点的水平距离，结果存入unordered_map中。区别在于，要把结点存入map结构时，若该水平距离已经被存入到map中，那就略过，以第一次存入的值为准。

以下结论依然成立：所有结点的水平距离，都是从0开始，执行若干次+1或-1操作后计算出来的。也就>是说，设树中最小的水平距离为leftmost，最大水平距离为rightmost，那么leftmost与rightmost之间的所有值都存在与unordered_map中。所以，我们只需要计算出leftmost和rightmost，然后令i从在[leftmost, rightmost]范围内递增，逐个从unordered_map中取出数据即可。
