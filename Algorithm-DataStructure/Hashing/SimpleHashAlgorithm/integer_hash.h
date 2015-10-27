#ifndef _INTEGER_HASH_
#define _INTEGER_HASH_

#include <stddef.h>
#include <stdint.h>

int division_hash(int k, size_t m);

int kunth_division_hash(int k, size_t m);

int multiplication_hash(int k, size_t m);

#endif
