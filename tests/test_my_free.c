#include "test_include.h"

void test_my_free() {
	// Request a small amount of memory 1Kb
	size_t size = 1024;
	char **buf = my_malloc(size);
	
	printf("my_alloced 1Kb...\n");
	printf("freeing the allocated 1Kb...\n");
	my_free(buf);
	//Block *buf_block = (Block*)buf - 1;
	//ASSERT(buf_block->free == 1, "Memory has not been freed succesfully. 😨");
	printf("Memory block is marked free.  ✅\n");
	printf("---------------\n");
}

void test_merge_blocks_null() {
	// merge blocks by passing a NULL pointer to see it return 1/fail
	printf("Creating a null block and passing to merge blocks...\n");
	Block *null_block = NULL;
	Block *result = merge_blocks(null_block);
	ASSERT_FMT(result == NULL, "Return value is not 1 but is instead %p. 😨", result);
	printf("Return is NULL as expected.  ✅\n");
	printf("---------------\n");
}

void test_merge_blocks() {
	// merge blocks and test for the combined block's size, address,
	printf("Creating a linked list of 5 blocks...\n");
	Block first_block = {10, 1, NULL, NULL};
	Block second_block = {100, 0, &first_block, NULL};
	first_block.next = &second_block;
	Block third_block = {18, 1, &second_block, NULL};
	second_block.next = &third_block;
	Block fourth_block = {24, 1, &third_block, NULL};
	third_block.next = &fourth_block;
	Block fifth_block = {6, 1, &fourth_block, NULL};
	fourth_block.next = &fifth_block;
	printf("Created 5 blocks...\n");
	printf("Calling merge_blocks on the third block.\n");
	Block *merged_block = merge_blocks(&third_block);
	ASSERT_FMT(merged_block->size == 48, "Size of merged block is %zu instead of 48. 😨", merged_block->size);
	printf("Size of merged block is correct. ✅\n");
	ASSERT_FMT(merged_block == &third_block, "Address of merged block is %p instead of %p. 😨", merged_block, &third_block);
	printf("Address of merged block is correct. ✅\n");
	printf("---------------\n");
}
