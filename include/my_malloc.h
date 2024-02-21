#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#define POOL_SIZE 1024 * 1024 * 100

#include <stddef.h> // for size_t

#include "block.h"

struct Block *my_malloc(size_t size);
struct Block *split_block(struct Block *block_to_split, size_t size);

#endif
