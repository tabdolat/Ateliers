PROJ = pg116-1718s1

BIN = array

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


#array

ex1.o : ${PROJ}/ex1.c
	${CC} ${CPPFLAGS} ${CCFALGS} ${PROJ}/ex1.c -c

array : ex1.o array_test.c
	${CC} ${CPPFLAGS} ${CCFALGS} ex1.o -o array array_test.c
