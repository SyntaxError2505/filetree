TARGET := ftree
CC := cc
CFLAGS := -std=c23 -Wall -Wextra

$(TARGET): main.c
	$(CC) -o $(TARGET) $(CFLAGS) main.c
