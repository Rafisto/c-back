CC = clang
CFLAGS = -Wall -Wextra -std=c11

SRC_DIR = .
BUILD_DIR = build
TARGET = server

SRCS := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/logging/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/logging/%.o: $(SRC_DIR)/logging/%.c
	mkdir -p $(BUILD_DIR)/logging
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(BUILD_DIR) $(TARGET)
