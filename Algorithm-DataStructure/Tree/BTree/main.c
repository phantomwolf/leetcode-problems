#include <glib.h>
#include "btree.h"

void btree_show(BNode *node)
{
    if(!node)
        return;
    GList *l = node->keys;
    while (l) {
        if (KEY_LIST_KEY(l) != G_MAXINT)
            g_print("%i, ", KEY_LIST_KEY(l));
        l = l->next;
    }
    g_print("\n");
    l = node->keys;
    while (l) {
        btree_show(KEY_LIST_CHILD(l));
        l = l->next;
    }
}

int main(int argc, char *argv[])
{
    BTree tree;
    btree_init(&tree);

    /* Insert 9 keys */
    for(int i = 1; i <= 9; ++i) {
        btree_insert(&tree, i);
    }
    /* Split node */
    btree_node_split(&tree, tree.root);
    btree_show(tree.root);

    return 0;
}
