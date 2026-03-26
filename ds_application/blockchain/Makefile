# Compiler and Flags
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g
LDFLAGS = -lssl -lcrypto # Assuming you're using OpenSSL for hashing

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Target executable name
TARGET = $(BIN_DIR)/blockchain_app

# Source files (finds all .c files in src and its subdirectories)
SRCS = $(SRC_DIR)/blockchain.c $(SRC_DIR)/hash.c $(SRC_DIR)/linkedList.c
# Alternatively, use: SRCS = $(shell find $(SRC_DIR) -name "*.c")

# Object files (maps src/*.c to obj/*.o)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Default rule
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
