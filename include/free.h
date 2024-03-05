#include "block.h"
#include <sys/mman.h>

unsigned char my_free(void *ptr);
Block *merge_blocks(Block* block);
