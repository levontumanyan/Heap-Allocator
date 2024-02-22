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

struct Block *create_initial_pool(size_t size);
void test_initial_pool_not_null(struct Block *first_pool);
void test_initial_pool_free(struct Block *first_pool);
void test_initial_pool_size(struct Block *first_pool);

int main() {
	size_t size = 1024;
	struct Block *initial_pool = create_initial_pool(size);
	test_initial_pool_not_null(initial_pool);
	test_initial_pool_free(initial_pool);
	test_initial_pool_size(initial_pool);
	return 0;
}

struct Block *create_initial_pool(size_t size) {
	printf("Initializing the allocator...\n");
	struct Block *first_pool = initialize_allocator(size);
	return first_pool;
}

void test_initial_pool_not_null(struct Block *first_pool) {
	printf("Checking if the initial pool is not null. ❓\n");
	ASSERT(first_pool != NULL, "The initial pool is null.");
	printf("The initial pool is not null. ✅\n");
}

void test_initial_pool_free(struct Block *first_pool) {
	printf("Checking if the initial pool is marked as free. ❓\n");
	ASSERT(first_pool->free == 1, "The initial pool is not free.");
	printf("The initial pool is marked as free. ✅\n");
}

void test_initial_pool_size(struct Block *first_pool) {
	printf("Checking if the initial pool's size is correct. ❓\n");
	ASSERT(first_pool->size == 1024, "The initial pool's size is not correct.");
	printf("The initial pool's size is correct as expected. (%zu bytes.) ✅\n", first_pool->size);
}
