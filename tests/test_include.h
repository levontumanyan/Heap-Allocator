#include <assert.h>
#include <stdio.h>

#include "allocator.h"
#include "my_malloc.h"
#include "free.h"

Block *create_initial_pool(size_t size);
void test_initial_pool_not_null(Block *first_pool);
void test_initial_pool_free(Block *first_pool);
void test_initial_pool_size(Block *first_pool);
void test_initial_pool_prev_null(Block *first_pool);
void test_initial_pool_next_null(Block *first_pool);
void test_singleton_behaviour(Block *initial_pool1);
void test_small_my_malloc();
void test_my_free();
void test_merge_blocks_null();
void test_merge_blocks();

#define ASSERT(condition, message) \
	do { \
		if (!(condition)) { \
			fprintf(stderr, "%s:%d: Assertion failed: %s. %s\n", __FILE__, __LINE__, #condition, message); \
			assert(condition); \
		} \
	} while(0)

#define ASSERT_FMT(condition, message, ...) \
	do { \
		if (!(condition)) { \
			fprintf(stderr, "%s:%d: Assertion failed: %s. ", __FILE__, __LINE__, #condition); \
			fprintf(stderr, message, __VA_ARGS__); \
			fprintf(stderr, "\n"); \
			assert(condition); \
		} \
	} while(0)
