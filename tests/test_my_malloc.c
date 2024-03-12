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

void test_mult_my_malloc_block() {
	// Request a small amount of memory 1Kb
	size_t size1 = 1024;
	char **buf1 = my_malloc(size1);

	// Request a small amount of memory 1Kb
	size_t size2 = 1024;
	char **buf2 = my_malloc(size2);

	// Request a small amount of memory 1Kb
	size_t size3 = 1024;
	char **buf3 = my_malloc(size3);

	// Request a small amount of memory 1Kb
	size_t size4 = 1024;
	char **buf4 = my_malloc(size4);

	Block *block = (Block*)buf4 - 1;
	printf("Address of buf 1 is: %p\n", buf1);
	printf("Address of buf 2 is: %p\n", buf2);
	printf("Address of buf 3 is: %p\n", buf3);
	printf("Address of buf 4 is: %p\n", buf4);

	printf("Size of block is: %zu\n", block->size);
	printf("---------------\n");
}
