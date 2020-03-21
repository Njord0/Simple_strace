CC = gcc
CFLAGS =  -Wall

SRC = $(shell find . -name '*.c')


tracer: $(SRC)
	$(CC) -o $@ $^ $(CFLAGS) 