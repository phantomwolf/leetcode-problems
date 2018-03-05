#ifndef _RBTREE_H_
#define _RBTREE_H_

#define BLACK   1
#define RED     0

// Binary Search Tree
typedef struct RBNode RBNode;
struct RBNode {
    int       key;        // key
    RBNode   *left;       // left child
    RBNode   *right;      // right child
    RBNode   *parent;     // parent
    char      color;      // either RED or BLACK

    RBNode(int k, char c = RED): key(k), left(nullptr), right(nullptr), parent(nullptr), color(c) {}
};

class RBTree {
    RBNode *root;
    RBNode *nil;     // NIL node

public:
    RBTree();
    RBNode *search(int key);
    void insert(int key);
    void insert_fixup(RBNode *node);

    // print structure of tree with preorder traversal
    void show(RBNode *node = nullptr);
};

#endif
