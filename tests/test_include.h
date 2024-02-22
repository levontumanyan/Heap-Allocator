#include <assert.h>
#include <stdio.h>

#include "allocator.h"

struct Block *create_initial_pool(size_t size);
void test_initial_pool_not_null(struct Block *first_pool);
void test_initial_pool_free(struct Block *first_pool);
void test_initial_pool_size(struct Block *first_pool);
void test_initial_pool_prev_null(struct Block *first_pool);
void test_initial_pool_next_null(struct Block *first_pool);
void test_singleton_behaviour(struct Block *initial_pool1);

#define ASSERT(condition, message) \
	do { \
		if (!(condition)) { \
			fprintf(stderr, "%s:%d: Assertion failed: %s. %s\n", __FILE__, __LINE__, #condition, message); \
			assert(condition); \
		} \
	} while(0)
