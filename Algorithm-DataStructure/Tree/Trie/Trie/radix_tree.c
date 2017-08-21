#include <stdio.h>

#define ALPHABET_SIZE 26

typedef struct RadixTreeNode RadixTreeNode;

struct RadixTreeNode
{
    char *key;
    size_t len;
    char children_count;
    struct RadixTreeNode *children[ALPHABET_SIZE];
};

void split(struct RadixTreeNode *node, int p)
{
}

int main (int argc, char *argv)
{

    return 0;
}
