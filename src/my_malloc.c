#include "allocator.h"
#include "my_malloc.h"

struct Block *my_malloc(size_t size) {
	// search for a free block in the linked list of blocks
	struct Block *current_block = initial_block;
	while (current_block != NULL) {
		if (current_block->free == 1) {
			// current block is free but let's check the size
			if (current_block->size < size) {
				// this block cannot serve for our needs
				current_block = current_block->next;	
			}
			else if (current_block->size == size)
			{
				return current_block;
			}
			else {
				// the size of the current block is greater than what is requested, we should break the block into two "chunks". Returning chunk is what we want to return, remaining is what is left over.
				return split_block(current_block, size);
			}
		} 
		else {
			current_block = current_block->next;
		}
	}
}

struct Block *split_block(struct Block *block_to_split, size_t size) {
	struct Block *returning_chunk = block_to_split;
	struct Block *remaining_chunk = (struct Block *)((char *)block_to_split + sizeof(struct Block) + size);
	
	returning_chunk->free = 0;
	returning_chunk->next = remaining_chunk;
	// update the prev block's next block
	if (block_to_split->prev != NULL) {
		block_to_split->prev->next = returning_chunk;
		returning_chunk->prev = block_to_split->prev;
	}
	returning_chunk->size = size;

	remaining_chunk->free = 1;
	// if block_to_split had a next block, we have to update it's prev block to returning_chunk
	if (block_to_split->next != NULL) {
		block_to_split->next->prev = remaining_chunk;
		remaining_chunk->next = block_to_split->next;
	}
	remaining_chunk->prev = returning_chunk;
	remaining_chunk->size = block_to_split->size - size - sizeof(struct Block);

	return returning_chunk;
}
