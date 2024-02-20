#include "allocator.h"

void initialize_allocator(size_t size) {
	// Allocate the memory pool

	initial_block = (struct Block *)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	// Check if mmap is successful
	if (initial_block == MAP_FAILED) {
		// Handle error
		return;
	}

	initial_block->size = size; // size of the block
	initial_block->free = 1; // mark it as free
	initial_block->next = NULL; // no next block currently
}
