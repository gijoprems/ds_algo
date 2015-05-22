TOPDIR=$(shell pwd)
INCDIR=$(TOPDIR)/include
INCLUDES=-I$(INCDIR)
CC=gcc
CFLAGS= -Wall $(INCLUDES)
LDFLAGS=

lib_src=src/sll.c
lib_obj=src/sll.o
tests_src=$(wildcard tests/*.c)
tests_exes=$(patsubst %.c,%,$(tests_src))

all: $(lib_obj) $(tests_exes)

$(lib_obj): $(lib_src)
	$(CC) $(CFLAGS) -c $< -o $@

src=$(patsubst %,%.c,$@)
bin=$(patsubst %,%,$@)

$(tests_exes): $(tests_src)
	@echo "create" $@
	$(CC) $(CFLAGS) $(LDFLAGS) $(src) $(lib_obj) -o $(bin)

distclean: clean
	rm -rf cscope*

clean:
	rm -rf *.o src/*.o tests/*.o $(tests_exes)
