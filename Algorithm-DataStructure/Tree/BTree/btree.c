#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include "btree.h"

gint bkey_cmp(gconstpointer a, gconstpointer b)
{
    BKey *x = (BKey *)a, *y = (BKey *)b;
    if (x->key == y->key)
        return 0;
    else if (x->key > y->key)
        return 1;
    else
        return -1;
}

void btree_init(BTree *tree)
{
    tree->root = (BNode *)g_malloc(sizeof(BNode));
    btree_node_init(tree->root);
}

void btree_node_init(BNode *node)
{
    node->parent    = NULL;
    node->size      = 0;

    BKey *edge_protector    = (BKey *)malloc(sizeof(BKey));
    edge_protector->key     = G_MAXINT;
    edge_protector->child   = NULL;
    node->keys              = g_list_append(NULL, edge_protector);
}

void btree_node_split(BTree *tree, BNode *node)
{
    if (node->size != 2*M - 1)
        return;
    BNode *new_node = (BNode *)malloc(sizeof(BNode));
    btree_node_init(new_node);

    GList *median = g_list_nth(node->keys, (2*M - 1)/2);
    /* left part */
    median->prev->next = NULL;
    BKey *edge_protector    = (BKey *)malloc(sizeof(BKey));
    edge_protector->key     = G_MAXINT;
    edge_protector->child   = ((BKey *)median->data)->child;
    node->keys              = g_list_append(node->keys, edge_protector);
    node->size              = M - 1;
    KEY_LIST_CHILD(median) = node;
    /* right part */
    median->next->prev = NULL;
    new_node->keys          = median->next;
    new_node->size          = M - 1;
    /* Create parent if necessary */
    BNode *parent = node->parent;
    if (parent == NULL) {
        parent = (BNode *)malloc(sizeof(BNode));
        btree_node_init(parent);
        tree->root = node->parent = parent;
    }
    new_node->parent = parent;
    /* Insert median into parent's keys list */
    GList *l = parent->keys;
    while (KEY_LIST_KEY(median) >= KEY_LIST_KEY(l)) {
        l = g_list_next(l);
    }
    if (l->prev) {
        l->prev->next = median;
    } else {
        parent->keys = median;
    }
    l->prev           = median;
    median->prev = l->prev;
    median->next = l;
    KEY_LIST_CHILD(median)       = node;
    KEY_LIST_CHILD(median->next) = new_node;
}

gboolean btree_node_is_leaf(BNode *node)
{
    GList *l = node->keys;
    while (l) {
        if (KEY_LIST_CHILD(l) != NULL)
            return FALSE;
        l = l->next;
    }
    return TRUE;
}

void btree_insert(BTree *tree, gint key)
{
    /* Split root node if necessary */
    if (tree->root->size == 2*M - 1)
        btree_node_split(tree, tree->root);

    BNode *node = tree->root;
    while (! btree_node_is_leaf(node)) {
        /* Search for the correct child */
        GList *l = node->keys;
        while (key >= KEY_LIST_KEY(l)) {
            l = l->next;
        }
        /* Split child node if necessary */
        if (KEY_LIST_CHILD(l)->size == 2*M - 1) {
            btree_node_split(tree, KEY_LIST_CHILD(l));
            if (key < KEY_LIST_KEY(l->prev)) {
                node = KEY_LIST_CHILD(l->prev);
                continue;
            }
        }
        node = KEY_LIST_CHILD(l);
    }
    /* Insert key into leaf node */
    BKey *k     = (BKey *)g_malloc(sizeof(BKey));
    k->key      = key;
    k->child    = NULL;
    node->keys  = g_list_insert_sorted(node->keys, k, bkey_cmp);
    ++node->size;
}
