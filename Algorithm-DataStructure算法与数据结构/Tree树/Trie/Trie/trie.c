#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <glib.h>

#define ALPHABET_SIZE       26

// Calculate array size
#define ARRAY_SIZE(a)       (sizeof(a) / sizeof(a[0]))

// Convert char to index of alphabet array
#define CHAR_TO_INDEX(c)    ((int)(c) - (int)'a')

// Trie node
struct TrieNode
{
    void *data;
    struct TrieNode *children[ALPHABET_SIZE];
    char children_count; // count of children nodes
    // is_leaf is true if node represents end of a word
    bool is_leaf;
};


struct TrieNode *trie_node_new(void *data, bool is_leaf)
{
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    memset(node->children, 0, sizeof(struct TrieNode *) * ALPHABET_SIZE);
    node->data              = data;
    node->children_count    = 0;
    node->is_leaf           = is_leaf;
    return node;
};


void trie_insert(struct TrieNode *root, const char *key, void *data)
{
    const char *p = key;
    struct TrieNode *n = root;
    while (*p != '\0') {
        size_t i = CHAR_TO_INDEX(*p);
        if (n->children[i] == NULL) {
            n->children[i] = trie_node_new(NULL, false);
            n->children_count++;
        }
        n = n->children[i];
        ++p;
    }
    n->is_leaf   = true;
    n->data      = data;
}


void *trie_search(struct TrieNode *root, const char *key)
{
    const char *p = key;
    struct TrieNode *n = root;
    while (*p != '\0' && n != NULL) {
        size_t i = CHAR_TO_INDEX(*p);
        n = n->children[i];
        ++p;
    }
    if (n == NULL || n->is_leaf == false)
        return NULL;
    return n->data;
}


void trie_delete(struct TrieNode *root, const char *key)
{
    const char *p = key;
    struct TrieNode *n = root;
    GQueue *stack = g_queue_new();
    while (*p != '\0' && n != NULL) {
        size_t i = CHAR_TO_INDEX(*p);
        n = n->children[i];
        g_queue_push_tail(stack, (gpointer *)n);
        ++p;
    }
    if (n == NULL || n->is_leaf == false) {
        g_queue_free(stack);
        return;
    }
    
    // We found the node
    n->is_leaf = false;
    while (!g_queue_is_empty(stack)) {
        n = g_queue_pop_tail(stack);
        struct TrieNode *parent = g_queue_peek_tail(stack);
        --p;
        // If n is leaf, or has children, break
        if (n->is_leaf == true || n->children_count != 0)
            break;
        // free node
        free(n);
        // Remove n from parent
        parent->children[CHAR_TO_INDEX(*p)] = NULL;
        parent->children_count--;
    }
    g_queue_free(stack);
}


int main(int argc, char *argv[])
{
    struct TrieNode *root = trie_node_new(NULL, false);

    // Insert
    int data1   = 11037;
    trie_insert(root, "leon", &data1);
    int data2   = 86;
    trie_insert(root, "baka", &data2);
    int data3   = 47;
    trie_insert(root, "ba", &data3);

    // Search
    char *keys[4] = {"leon", "ba", "bak", "baka"};
    for (int i = 0; i < 4; ++i) {
        int *p = (int *)trie_search(root, keys[i]);
        if (p == NULL)
            printf("key '%s' not found\n", keys[i]);
        else
            printf("%s = %d\n", keys[i], *p);
    }

    // Delete
    printf("Deleting key 'baka'...\n");
    trie_delete(root, "baka");

    // Search again
    for (int i = 1; i < 4; ++i) {
        int *p = (int *)trie_search(root, keys[i]);
        if (p == NULL)
            printf("key '%s' not found\n", keys[i]);
        else
            printf("%s = %d\n", keys[i], *p);
    }

    return 0;
}
