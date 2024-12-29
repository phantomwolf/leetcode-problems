检测一个二叉树是否为完全二叉树
==================================================================
A complete binary tree is a binary tree whose all levels except the last level are completely filled and all the leaves in the last level are all to the left side.

The following trees are examples of Complete Binary Trees
    1
  /   \
 2     3
  
       1
    /    \
   2       3
  /
 4

       1
    /    \
   2      3
  /  \    /
 4    5  6

The following trees are examples of Non-Complete Binary Trees
    1
      \
       3
  
       1
    /    \
   2       3
    \     /  \   
     4   5    6

       1
    /    \
   2      3
         /  \
        4    5

迭代版本
----------------------
使用队列辅助的宽度优先搜索，可以用于这个问题。我们按照广度优先顺序(也叫level order traversal)遍历树的结点，如果我们遇到一个没有左孩子的结点，那么它必须没有右结点，并且接下来的结点都必须是叶子结点。否则这棵树就不是完全二叉树。
