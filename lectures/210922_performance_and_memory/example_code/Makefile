# OS X users should use additionally gcc-6, gcc will invoke the Clang compiler
CC=gcc-6
CFLAGS=-std=c11 -Wall -Werror -Wextra -pedantic -O1
PROGRAMS=sum_rows
LIBS=

.PHONY: clean all

all:
	make $(PROGRAMS)

sum_rows: sum_rows.c
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm -f $(PROGRAMS)
	# rm -fr $(foreach prg,$(PROGRAMS),$(prg).dSYM)
