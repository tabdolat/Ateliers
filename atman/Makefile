BIN = node_test

CC ?= cc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS =

.PHONY: all test build clean

all: build test

build: ${BIN}

test: build

	@for e in ${BIN}; do \
	echo $${e}; ./$${e}; \
	done


clean:
	rm -f *.o ${BIN} *~

node.o : node.c node.h
	${CC} ${CFLAGS} node.c -c
node_test: node.o
	${CC} node.o -o $@