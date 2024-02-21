#include "allocator.h"

struct Block *initialize_allocator(size_t size) {
	// Declare initial_block as a static variable
	static struct Block *initial_block = NULL;

	// if the initial memory pool has been allocated just return it
	if (initial_block != NULL) {
		return initial_block;
	}

	// Allocate the memory pool
	initial_block = (struct Block *)mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	// Check if mmap is successful
	if (initial_block == MAP_FAILED) {
		// Handle error
		return NULL;
	}

	initial_block->size = size; // size of the block
	initial_block->free = 1; // mark it as free
	initial_block->next = NULL; // no next block currently
	initial_block->prev = NULL; // no prev block currently

	return initial_block;
}

void allocate_more() {
	// in case if more allocation chunks are needed.	
}
