TARGET := ftree
CC := cc
CFLAGS := -std=c23 -Wall -Wextra -O2
SOURCE = $(shell find . -type f -name "*.c")

$(TARGET): main.c
	$(CC) -o $(TARGET) $(CFLAGS) $(SOURCE)

format:
	clang-format -i $(SOURCE)

.PHONY: format
