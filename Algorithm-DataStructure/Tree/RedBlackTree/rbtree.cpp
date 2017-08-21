#include "rbtree.h"
#include <stack>
#include <iostream>

using namespace std;


// constructor
RBTree::RBTree() {
    nil  = new RBNode(0, BLACK);
    nil->left = nil->right = nil->parent = nil;
    root = nil;
}


RBNode *RBTree::search(int key) {
    RBNode *node = root;
    while (node != nil) {
        if (key == node->key)
            return node;
        else if (key < node->key)
            node = node->left;
        else
            node = node->right;
    }
    return node;
}

void RBTree::insert(int key) {
    RBNode *node = root, *parent = nullptr;
    while (node != nil && node->key != key) {
        if (key == node->key)
            return;     // key already in tree. No need to insert.
        else if (key < node->key) {
            parent = node;
            node = node->left;
        } else {
            parent = node;
            node = node->right;
        }
    }

    // Create a new RBNode
    node = new RBNode(key, RED);
    node->left = node->right = node->parent = nil;
    if (parent == nullptr) {
        root = node;
        root->color = BLACK;
        return;
    }
    if (key < parent->key) {
        parent->left = node;
    } else {
        parent->right = node;
    }
    node->parent = parent;
    if (parent->color == RED)
        insert_fixup(node);
}

void RBTree::insert_fixup(RBNode *x) {
    // parent of root is nil. nil is always black
    RBNode *p, *u, *g;
    while (x->parent->color == RED) {
        p = x->parent;
        g = p->parent;
        if (p = p->parent->left)
            u = p->parent->right;
        else
            u = p->parent->left;
        // case 1
        if (u->color == RED) {
            p->color = u->color = BLACK;
            p->parent->color = RED;
            x = p->parent;
            continue;
        }
        if (p == g->left) {
        } else {
        }
    }
    root->color = BLACK;
}

void RBTree::show(RBNode *node) {
    if (node == nullptr)
        node = root;
    if (node == nil)
        return;
    cout << node->key;
    cout << ((node->color == BLACK) ? "B" : "R");
    if (node->left == nil && node->right == nil) {
        goto newline;
    }
    cout << " ( ";
    if (node->left != nil)
        show(node->left);
    if (node->right != nil) {
        cout << " , ";
        show(node->right);
    }
    cout << " ) ";

newline:
    if (node == root)
        cout << endl;
}
