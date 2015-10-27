#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "my_set.h"

MySet *set_create(size_t size)
{
    MySet *set = (MySet *)malloc(sizeof(MySet));
    set_init(set, size);
    return set;
}

void set_init(MySet *set, size_t size)
{
    set->size    = size;
    set->count   = 0;
    set->data    = (char **)malloc(sizeof(char *) * size);
    memset(set->data, 0, sizeof(char *) * size);
    set->deleted = "\3";
}

void set_destroy(MySet *set)
{
    for (int i = 0; i < set->size; ++i) {
        if (set->data[i] != NULL && set->data[i] != set->deleted)
            free(set->data[i]);
    }
    free(set->data);
    free(set);
}

size_t sdbm(char *str)
{
    return 701;
    size_t index = 0;
    int c;
    while (c = *str++) {
        index = c + (index << 6) + (index << 16) - index;
    }
    fprintf(stderr, "sdbm: '%s' => %lu\n", str, index);
    return index;
}

/* 二次探索法 */
bool set_insert(MySet *set, char *key)
{
    if (set->count >= set->size) {
        return false;
    }
    size_t orig_index = sdbm(key);
    size_t index = orig_index % set->size;
    int i = 1;
    fprintf(stderr, "set_insert: %s => %lu\n", key, index);
    while (set->data[index] != NULL && set->data[index] != set->deleted) {
        index = (orig_index + i * i) % set->size;
        fprintf(stderr, "set_insert: %s => %lu\n", key, index);
        ++i;
    }
    // Insert the key
    size_t len = strlen(key);
    set->data[index] = (char *)malloc(sizeof(char) * (len + 1));
    strncpy(set->data[index], key, len + 1);
    return true;
}

bool set_search(MySet *set, char *key)
{
    size_t orig_index = sdbm(key);
    size_t index = orig_index % set->size;
    int i = 1;
    fprintf(stderr, "set_search: %s at %lu?\n", key, index);
    while (set->data[index] != NULL &&
           strcmp(set->data[index], key) != 0) {
        index = (orig_index + i * i) % set->size;
        fprintf(stderr, "set_search: %s at %lu?\n", key, index);
        ++i;
    }
    return (set->data[index] == NULL) ? false : true;
}

bool set_delete(MySet *set, char *key)
{
    size_t orig_index = sdbm(key);
    size_t index = orig_index % set->size;
    int i = 1;
    fprintf(stderr, "set_delete: delete %s from %lu?\n", key, index);
    while (set->data[index] != NULL &&
           strcmp(set->data[index], key) != 0) {
        index = (orig_index + i * i) % set->size;
        fprintf(stderr, "set_delete: delete %s from %lu?\n", key, index);
        ++i;
    }
    if (set->data[index] == NULL)
        return false;
    free(set->data[index]);
    set->data[index] = set->deleted;
    return true;
}
