CC=clang++
CXXFLAGS=-std=c++14 -pedantic -Wall -o3

SRC=src/mouse.cc
BIN=mouse

all:
	${CC} ${CXXFLAGS} ${SRC} -o ${BIN}

.PHONY: clean
clean:
	${RM} ${BIN}