#include "test_include.h"

void test_small_my_malloc() {
	// Request a small amount of memory 1Kb
	size_t size = 1024;
	char **buf = my_malloc(size);

	printf("Checking my_alloc for a small amount of allocation 1Kb... ❓\n");
	ASSERT(buf != NULL, "my_alloc for a small amount of allocation failed. 😨");
	printf("my_alloc returned a not null pointer.  ✅\n");
	printf("---------------\n");
}

void test_my_free() {
	// Request a small amount of memory 1Kb
	size_t size = 1024;
	char **buf = my_malloc(size);
	
	printf("my_alloced 1Kb...\n");
	printf("Checking to see if the block containing this memory is marked not free. ❓\n");
	Block *block = (Block *)buf - 1;
	ASSERT_FMT(block->free == 0, "Memory block is not marked not-free. The value of free is: %d 😨", block->free);
	printf("Memory block is marked not-free.  ✅\n");
	printf("---------------\n");
}
