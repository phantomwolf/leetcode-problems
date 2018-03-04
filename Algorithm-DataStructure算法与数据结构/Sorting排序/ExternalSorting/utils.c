#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

void gen_data_file(const char *path, size_t count)
{
    srand(time(NULL));

    int buffer[1024];
    FILE *file = fopen(path, "wb");

    size_t n = 0;
    while (count != 0) {
        buffer[n++] = rand() % INT_MAX;
        if (n == 1024 || n == count) {
            size_t items = 0;
            while (items != n) {
                items += fwrite(buffer + items, sizeof(int), n - items, file);
            }
            count -= n;
            n = 0;
        }
    }

    fclose(file);
}

void print_data_file(const char *path)
{
    int buffer[1024];
    FILE *file = fopen(path, "rb");

    size_t items_read;
    printf("%s: ", path);
    while ((items_read = fread(buffer, sizeof(int), 1024, file)) != 0) {
        for (int i = 0; i < items_read; ++i) {
            printf("%d, ", buffer[i]);
        }
    }
    fclose(file);
    puts("");
}

bool file_is_sorted(const char *path)
{
    int buffer[1024];
    int prev = INT_MIN;
    size_t total = 0;

    FILE *file = fopen(path, "rb");
    size_t items_read;
    while ((items_read = fread(buffer,
                               sizeof(int),
                               1024,
                               file)) != 0) {
        for (int i = 0; i < items_read; ++i) {
            if (prev > buffer[i]) {
                fprintf(stderr, "%s not sorted: %d vs %d\n", prev, buffer[i]);
                fclose(file);
                return false;
            }
            prev = buffer[i];
            ++total;
        }
    }
    fclose(file);
    fprintf(stderr, "%u items compared\n", total);
    return true;
}
