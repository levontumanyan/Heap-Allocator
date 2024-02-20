struct Block {
	// header
	
	// keeps track of the size of the block
	size_t size;
	// flag to indicate whether the block is free or not - 1 for free, 0 - for not free
	unsigned char free;

	// next block in the list
	struct Block *next;
};
