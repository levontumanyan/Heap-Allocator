#ifndef BLOCK_H
#define BLOCK_H

#include <stddef.h> // for size_t

typedef struct Block {
	// header
	
	// keeps track of the size of the block
	size_t size;
	// flag to indicate whether the block is free or not - 1 for free, 0 - for not free
	unsigned char free;

	// previous block in the list
	struct Block *prev;

	// next block in the list
	struct Block *next;
} Block;

#endif
