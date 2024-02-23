#include "allocator.h"

Block *get_initial_pool() {
	static Block *initial_pool = NULL;
	return initial_pool;
}

Block *initialize_allocator(size_t size) {
	// Declare initial_pool as a static variable
	Block *initial_pool = get_initial_pool();

	// if the initial memory pool has been allocated just return it
	if (initial_pool != NULL) {
		return initial_pool;
	}

	// Allocate the memory pool
	initial_pool = (Block *) mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

	// Check if mmap is successful
	if (initial_pool == MAP_FAILED) {
		// Handle error
		return NULL;
	}

	initial_pool->size = size; // size of the block
	initial_pool->free = 1;    // mark it as free
	initial_pool->prev = NULL; // no prev block currently
	initial_pool->next = NULL; // no next block currently

	return initial_pool;
}

Block *allocate_more(size_t size) {
	// If initial memory hasn't been allocated return NULL
	if (get_initial_pool() == NULL) {
		return NULL;
	}
	
	// in case if more allocation pool is needed. Allocate new memory pool
	Block *new_pool = (Block *) mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
	
	// Check if mmap is successful
	if (new_pool == MAP_FAILED) {
		// Handle error
		return NULL;
	}

	new_pool->size = size;
	new_pool->free = 1;
	new_pool->next = NULL;
	// determine the last block to make it the prev of the new pool
	Block *current_block = get_initial_pool();

	while (current_block != NULL) {
		current_block = current_block->next;
	}
	new_pool->prev = current_block;
	current_block->next = new_pool;

	return new_pool;
}
