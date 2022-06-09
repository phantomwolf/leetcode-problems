#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdbool.h>

void gen_data_file(const char *file, size_t count);

void print_data_file(const char *path);

bool file_is_sorted(const char *path);

#endif
