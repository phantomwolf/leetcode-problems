#ifndef _MY_HASH_H
#define _MY_HASH_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct MySet MySet;

/* string */
struct MySet
{
    size_t size;    // maximum amount of keys can be inserted
    size_t count;   // current amount of keys inserted
    char **data;
    char *deleted;
};

MySet *set_create(size_t size);

void set_init(MySet *set, size_t size);

void set_destroy(MySet *set);

bool set_insert(MySet *set, char *key);

bool set_search(MySet *set, char *key);

bool set_delete(MySet *set, char *key);

size_t sdbm(char *str);

#endif
