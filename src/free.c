#include "free.h"

/* 
return 0 if success and non-zero otherwise
- at some point can add checks to make sure the passed pointer does point to a block
- make sure to coalesce free blocks next to each other - to reduce fragmentation
*/
unsigned char my_free(void *ptr) {
	// do i need a block finder function here
	Block *block = (Block*)ptr - 1;

	if (block->free == 1) {
		return 1;
	}
	else if (block->free == 0)
	{	
		// Mark the block as free
		block->free = 1;
		return 0;
	}
}

unsigned char merge_blocks(Block* block) {
	/* thinking about doing a for loop, at first to the "left" of the passed block.
	we go to the previous block check if it is free, if it is we merge them together
	when we merge we have to make sure to remove the info about the merging block */

	// let's keep track of the size of the blocks counted so far
	size_t new_size;
	// first let's go back until we see a non-free block
	Block *current_block = block;
	while(current_block != NULL || current_block->free == 0) {
		new_size += current_block->size;
		current_block = current_block->prev;
	}

	/* when we come out of the for loop current_block will either be NULL or not free. in the case when current_block is NULL means that the next block of current block should become the new beginning block.  */
}
