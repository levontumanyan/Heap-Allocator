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
	// thinking about doing a for loop, at first to the "left" of the passed block.
	// we go to the previous block check if it is free, if it is we merge them together
	// when we merge we have to make sure to remove the info about the merging block
}
