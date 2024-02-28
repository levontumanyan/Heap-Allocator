#include "test_include.h"

void test_my_free() {
	// Request a small amount of memory 1Kb
	size_t size = 1024;
	char **buf = my_malloc(size);
	
	printf("my_alloced 1Kb...\n");
	printf("freeing the allocated 1Kb...\n");
	my_free(buf);
	Block *buf_block = (Block*)buf - 1;
	ASSERT(buf_block->free == 1, "Memory has not been freed succesfully. 😨");
	printf("Memory block is marked free.  ✅\n");
	printf("---------------\n");
}

void test_merge_blocks() {
	// merge blocks by passing a NULL pointer to see it return 1/fail
	
}
