#include <stddef.h>
#include <stddef.h>

#include <stdlib.h>

struct Block {
	// header
	
	// keeps track of the size of the block
	size_t size;
	// flag to indicate whether the block is free or not - 1 for free, 0 - for not free
	unsigned char free;

	// payload

};
