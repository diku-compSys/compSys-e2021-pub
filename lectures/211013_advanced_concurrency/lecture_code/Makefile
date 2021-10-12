CFLAGS=-O3 -pthread -Wall -Wextra -pedantic
CC=gcc
PROGS=fibs fibs-futures fibs-mt fibs-threadpool fibs-threadpool-spin

all: $(PROGS)

%: %.c
	$(CC) -o $@ $< $(CFLAGS)

clean:
	rm -f $(PROGS)
