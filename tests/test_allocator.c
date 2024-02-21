#include <assert.h>
#include <stdio.h>

#include "allocator.h"

#define ASSERT(condition, message) \
    do { \
        if (!(condition)) { \
            fprintf(stderr, "%s:%d: Assertion failed: %s. %s\n", __FILE__, __LINE__, #condition, message); \
            assert(condition); \
        } \
    } while(0)

void test_initialize_allocator();

int main() {
	test_initialize_allocator();
	return 0;
}

void test_initialize_allocator() {
	printf("Running the test_initialize_allocator test.\n");
	size_t size = 1024;
	printf("Initializing the allocator...\n");
	struct Block *first_pool = initialize_allocator(size);

	printf("Checking if the initial pool is not null. ❓\n");
	ASSERT(first_pool != NULL, "The initial pool is null.");
	printf("The initial pool is not null. ✅\n");

	printf("Checking if the initial pool is marked as free. ❓\n");
	ASSERT(first_pool->free == 1, "The initial pool is not free.");
	printf("The initial pool is marked as free. ✅\n");
}
