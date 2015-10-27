#include <stdio.h>
#include <stdlib.h>

#include "utils.h"


#define TOTAL_RECORDS   100000
#define BUFFER_SIZE     10240
#define ARRAY_SIZE      1024


int int_cmp(const void *a, const void *b)
{
    if (*(int *)a == *(int *)b)
        return 0;
    else if (*(int *)a < *(int *)b)
        return -1;
    else
        return 1;
}

void external_merge_sort(const char *path, const char *output)
{
    int *buffer = (int *)malloc(sizeof(int) * BUFFER_SIZE);
    size_t items_read;

    char tmp_path[64];
    FILE *infile = fopen(path, "rb");
    int tmp_count = 0;
    while ((items_read = fread(buffer,
                               sizeof(int),
                               BUFFER_SIZE,
                               infile)) != 0) {
        qsort(buffer, items_read, sizeof(int), int_cmp);
        // Write to tmp file
        snprintf(tmp_path,
                 64,
                 "/tmp/external-merge-sort-%d.tmp",
                 tmp_count++);
        FILE *tmpfile = fopen(tmp_path, "wb");
        while (items_write = fwrite(buffer)

        while (items_write != items_read) {
            items_write += fwrite(buffer + items_write,
                                  sizeof(int),
                                  items_read - items_write,
                                  tmpfile);
        }
        fclose(tmpfile);
    }
    fclose(infile);
    free(buffer);

    // Merge tmp files
    int **arrays = (int **)malloc(sizeof(int *) * tmp_count);
    for (int i = 0; i < tmp_count; ++i) {
        arrays[i] = (int *)malloc(sizeof(int) * ARRAY_SIZE);
        items_read = 0
    }

    for (int i = 0; i < tmp_count; ++i) {
        free(arrays[i]);
    }
    free(arrays);
}

int main(int argc, char *argv[])
{
    const char *path = "data.bin";
    size_t count = TOTAL_RECORDS;
    gen_data_file(path, count);

    external_merge_sort(path, "sorted.bin");

    return 0;
}
