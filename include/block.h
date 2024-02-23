#ifndef BLOCK_H
#define BLOCK_H

typedef Block {
	// header
	
	// keeps track of the size of the block
	size_t size;
	// flag to indicate whether the block is free or not - 1 for free, 0 - for not free
	unsigned char free;

	// previous block in the list
	Block *prev;

	// next block in the list
	Block *next;
} Block;

#endif
