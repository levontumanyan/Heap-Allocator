#include "test_include.h"

void test_small_malloc() {
	size_t size = 1024 * 1024;
	my_malloc(size);
	

	printf("Checking if the initial pool's size is correct. ❓\n");
	ASSERT(first_pool->size == 1024, "The initial pool's size is not correct. 😨");
	printf("The initial pool's size is correct as expected. (%zu bytes.) ✅\n", first_pool->size);
}
