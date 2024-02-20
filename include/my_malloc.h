#ifndef MY_MALLOC_H
#define MY_MALLOC_H

#include <stddef.h> // for size_t
#include "block.h"

struct Block *my_malloc(size_t size);

#endif
