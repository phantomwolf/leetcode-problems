二叉树树的遍历
============================
Morris遍历
---------------------
Morris遍历既不需要栈的辅助，也不需要递归。过程如下：

用current变量指代当前node，令current = root，当current不为NULL时：如果current没有左孩子，就访问它，并向右前进；如果current有左孩子，就将current设置为它的左子树里最右结点的右孩子，然后向左前进。

尽管树被修改，但在遍历过程中会进行恢复。设一个有左孩子的结点为parent，其左子树最右结点为pre，那么在遍历过程中会经过parent两次：第一次，我们将parent设为了pre的右孩子；第二次，我们访问完了pre，接下来要访问parent，顺便去掉pre到parent的链接。
