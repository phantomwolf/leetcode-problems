# 101. Symmetric Tree
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:

![example1](symtree1.jpg)

Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:

![example1](symtree2.jpg)

Input: root = [1,2,2,null,3,null,3]
Output: false

Constraints:

* The number of nodes in the tree is in the range [1, 1000].
* -100 <= Node.val <= 100
 
Follow up: Could you solve it both recursively and iteratively?

## Solution 1: Recursive
To verify the tree is symmetric, we need 2 pointers: one goes left and the other goes right, or vice versa. It's simple to do this in iterative traversal, but how to do this in recursive function?

Recall what we learned from the "lowest common ancestor" problem. We can create a recursive method with 2 parameters, each is a TreeNode. In the function, we verify the current node and recursively verify the subtrees.

```java
    private boolean isMirror(TreeNode a, TreeNode b) {
        if (a == null && b == null) {
            return true;
        }
        if (a == null || b == null) {
            // Only 1 of a and b is null
            return false;
        }
        if (a.val != b.val) {
            return false;
        }
        return isMirror(a.left, b.right) && isMirror(a.right, b.left);
    }
```

