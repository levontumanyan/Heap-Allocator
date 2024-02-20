#include <stddef.h> // Include the header file for NULL

#include "block.h"
#include <sys/mman.h> // Include the header file for mmap

// initial size of the memory pool
#define INITIAL_POOL_SIZE 4096

// Global pointer to the first block
struct Block *initial_block = NULL;

void initialize_allocator(size_t size);
