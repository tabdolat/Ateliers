PROJ = pg116-1819s1

BIN = node

CC ?= cc
CPPFLAGS = -I ${PROJ}
CFLAGS = -Wall -Wextra -std=c99 -g

.PHONY: all test build clean

all: build test

build: ${BIN}

test: build
	@for e in ${BIN}; do \
	echo $${e}; ./$${e}; \
	done

clean:
	rm -f *.o ${BIN} *~


ex1.o: ${PROJ}/ex1.c ${PROJ}/node.h
	${CC} ${CPPFLAGS} ${CFLAGS}  ${PROJ}/ex1.c -c

node.o: ${PROJ}/node.c
	${CC} ${CPPFLAGS} ${CFLAGS} ${PROJ}/node.c -c

node: ex1.o node.o tests.c
	${CC} ${CPPFLAGS} ${CFLAGS} ex1.o node.o tests.c -o node
