#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#define POOL_SIZE 1024 * 1024 * 10 // 10 Mb

#include <stddef.h> // Include the header file for NULL
#include <sys/mman.h> // Include the header file for mmap

#include "block.h"

Block *initialize_allocator(size_t size);
Block *allocate_more(size_t size);

#endif
