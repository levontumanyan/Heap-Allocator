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

void test_my_malloc_block() {
	// Request a small amount of memory 1Kb
	size_t size = 1024;
	char **buf = my_malloc(size);

	Block *block = (Block*)buf - 1;
	printf("Size of block is: %zu\n", block->size);
	printf("---------------\n");
}
