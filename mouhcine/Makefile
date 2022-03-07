PROJ = pg116-1819s1

BIN = node tree

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

node: ex1.o node.o node_tests.c
	${CC} ${CPPFLAGS} ${CFLAGS} ex1.o node.o node_tests.c -o node




ex2.o: ${PROJ}/ex2.c ${PROJ}/node.h
	${CC} ${CPPFLAGS} ${CFLAGS}  ${PROJ}/ex2.c -c

ntree.o: ${PROJ}/ntree.c
	${CC} ${CPPFLAGS} ${CFLAGS} ${PROJ}/ntree.c -c 

tree: ex1.o ex2.o node.o tree_tests.c
	${CC} ${CPPFLAGS} ${CFLAGS} ex1.o ex2.o node.o tree_tests.c -o tree
