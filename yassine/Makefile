NOD_DIR = node

BIN = node_test

CC ?= cc
CPPFLAGS = -I ${NOD_DIR}
CFLAGS = -Wall -Wextra -std=c99 -g -O0
LDFLAGS =

.PHONY: all test build clean

all: build test

build: ${BIN}

test: build
	@for e in ${BIN}; do \
	echo $${e}; ./$${e}; \
	done

ex1.o: ${NOD_DIR}/ex1.c ${NOD_DIR}/node.h
	${CC} ${CPPFLAGS} ${CFLAGS} ${NOD_DIR}/ex1.c -c

ex2.o: ${NOD_DIR}/ex2.c ${NOD_DIR}/node.h ${NOD_DIR}/ntree.h
	${CC} ${CPPFLAGS} ${CFLAGS} ${NOD_DIR}/ex2.c -c

ex3.o: ${NOD_DIR}/ex3.c ${NOD_DIR}/node.h ${NOD_DIR}/ntree.h
	${CC} ${CPPFLAGS} ${CFLAGS} ${NOD_DIR}/ex3.c -c

ex4.o: ${NOD_DIR}/ex4.c ${NOD_DIR}/node.h ${NOD_DIR}/ntree.h
	${CC} ${CPPFLAGS} ${CFLAGS} ${NOD_DIR}/ex4.c -c

ex5.o: ${NOD_DIR}/ex5.c ${NOD_DIR}/node.h ${NOD_DIR}/ntree.h
	${CC} ${CPPFLAGS} ${CFLAGS} ${NOD_DIR}/ex5.c -c

node.o: ${NOD_DIR}/node.c ${NOD_DIR}/node.h 
	${CC} ${CPPFLAGS} ${CFLAGS} ${NOD_DIR}/node.c -c

ntree.o: ${NOD_DIR}/node.h ${NOD_DIR}/ntree.h ${NOD_DIR}/ntree.c
	${CC} ${CPPFLAGS} ${CFLAGS} ${NOD_DIR}/ntree.c -c

node_test.o: ${NOD_DIR}/node.h ${NOD_DIR}/ntree.h ${NOD_DIR}/ntree.c
	${CC} ${CPPFLAGS} ${CFLAGS} ${NOD_DIR}/node_test.c -c

node_test: node_test.o ex1.o ex2.o ex3.o ex4.o ex5.o ntree.o node.o
	${CC} node_test.o ex1.o ex2.o ex3.o ex4.o ex5.o ntree.o node.o -o $@ ${LDFLAGS}

clean:
	rm ./node_test *.o
