#include "test_include.h"

int main() {
	size_t size = 1024;
	Block *initial_pool = create_initial_pool(size);
	test_initial_pool_not_null(initial_pool);
	test_initial_pool_free(initial_pool);
	test_initial_pool_size(initial_pool);
	test_initial_pool_prev_null(initial_pool);
	test_initial_pool_next_null(initial_pool);
	test_singleton_behaviour(initial_pool);
	return 0;
}
