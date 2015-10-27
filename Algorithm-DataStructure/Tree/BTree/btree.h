#ifndef __BTREE_H__
#define __BTREE_H__

#include <glib.h>
#include <stddef.h>

/* 模拟一个B树实现，不涉及实际的磁盘读写 */

/* 最小子节点数 */
#define M 3

#define KEY_LIST_DATA(L)        ((BKey *)((L)->data))
#define KEY_LIST_KEY(L)         (KEY_LIST_DATA(L)->key)
#define KEY_LIST_CHILD(L)       (KEY_LIST_DATA(L)->child)

typedef struct BKey BKey;

struct BKey
{
    gint            key;
    struct BNode   *child;
};

typedef struct BNode BNode;

struct BNode
{
    struct BNode   *parent;
    gsize           size;       /* Current amount of keys */
    GList          *keys;       /* GList of keys, including an edge protector */
};

typedef struct BTree BTree;

struct BTree
{
    struct BNode   *root;
};

gint btree_key_compare(gconstpointer a, gconstpointer b);

void btree_init(BTree *tree);
void btree_node_init(BNode *node);
void btree_node_split(BTree *tree, BNode *node);

gboolean btree_node_is_leaf(BNode *node);

/* Insert a key(In real use, together with its data) */
void btree_insert(BTree *tree, gint key);

#endif
