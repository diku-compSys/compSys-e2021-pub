CFLAGS=-O3 -Wall -Wextra -std=c99
CC=gcc

all: collatz 1darray

collatz: collatz.c
	$(CC) collatz.c -o collatz $(CFLAGS)

1darray: 1darray.c
	$(CC) 1darray.c -o 1darray $(CFLAGS)

libcollatz.so: collatz.c
	$(CC) collatz.c -fPIC -shared -o libcollatz.so $(CFLAGS)

mul.s: mul.c
	gcc mul.c -S $(CFLAGS)
