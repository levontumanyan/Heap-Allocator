#include <assert.h>

#include "allocator.h"

int main() {
	test_initialize_allocator();
	return 0;
}

void test_initialize_allocator() {
	size_t size = 1024;
	struct Block *first_pool = initialize_allocator(size);
	assert(first_pool != NULL);
}
