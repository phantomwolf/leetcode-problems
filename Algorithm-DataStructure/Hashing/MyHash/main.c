#include <stdio.h>

#include "my_set.h"



int main()
{
    char *keys[6] = {
        "charlie",
        "echo",
        "golf",
        "hotel",
        "india",
        "alpha",
    };

    MySet *set = set_create(1024);
    for (int i = 0; i < 6; ++i) {
        set_insert(set, keys[i]);
    }
    // Delete
    set_delete(set, "echo");
    // Search
    char *keys_searched[3] = {
        "alpha",
        "baka",
        "echo",
    };
    for (int i = 0; i < 3; ++i) {
        if (set_search(set, keys_searched[i])) {
            printf("Key %s found\n", keys_searched[i]);
        } else {
            printf("Key %s not found\n", keys_searched[i]);
        }
    }

    // Insert again
    set_insert(set, "echo");
    // Search again
    if (set_search(set, "echo")) {
        printf("Key %s found\n", "echo");
    } else {
        printf("Key %s not found\n", "echo");
    }

    set_destroy(set);

    return 0;
}
