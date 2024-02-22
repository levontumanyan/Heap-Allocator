CC := clang
CFLAGS := -Wall -Wextra -Iinclude

SRC_DIR := src
OBJ_DIR := bin
BIN_DIR := bin

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

TARGET := $(BIN_DIR)/allocate

$(TARGET): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/*.h
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: tests
# Rule to build the tests
tests: tests/test_initialize_allocator.c src/allocator.c src/my_malloc.c
	$(CC) $(CFLAGS) -o bin/test_allocator $^

# Rule to run the tests
test: tests
	./bin/test_allocator

.PHONY: clean

clean:
	rm -rf $(OBJ_DIR)/*.o $(TARGET)
