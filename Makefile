# Makefile

CXX=g++
CXX_FLAG = --std=c++11 -g

all: main

main: main.o maze.o
	${CXX} $(CXX_FLAG) -o main main.o maze.o

main.o: main.cpp
	${CXX} -c $(CXX_FLAG) main.cpp

maze.o: maze.cpp
	${CXX} -c $(CXX_FLAG) maze.cpp

clean:
	rm -rf main *.o
