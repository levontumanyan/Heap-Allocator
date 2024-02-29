#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include <stddef.h> // for size_t

#include "block.h"

void *my_malloc(size_t size);
Block *split_block(Block *block_to_split, size_t size);

#endif
