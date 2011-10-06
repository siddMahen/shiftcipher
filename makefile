CC = gcc
CFLAGS = -I.

OBJS = ./build/main.o

shiftcipher: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS)
	@rm ./build/*

./build/main.o:
	$(CC) -c ./src/main.c
	@mv main.o ./build/main.o

.PHONY: clean

clean:
	rm ./build/*
	rm shiftcipher
