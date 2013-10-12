# Made by Thiago Vieira
# The option -c in gcc: Compile and assemble, but do not link
CC=gcc

all: build clearafter

build: mainExato.o vector.o bitmask.o
	$(CC) main.o graph.o vector.o heap.o pair.o queue.o -o tp1

mainHeuristica.o:
	$(CC) -c mainHeuristica.c -o tp2h.o

mainExato.o: bitmask.h
	$(CC) -c mainExato.c -o tp2e.o

bitmask.o: vector.h
	$(CC) -c bitmask.c -o bitmask.o

vector.o:
	$(CC) -c vector.c -o vector.o

#Clear temporary files after compiling
clearafter:
	#Option -r: Remove recursive and
	#Option -f: ignore nonexistent files, never prompt
	rm -rf *.o
	rm -rf *~ #Remove temporary files

clear: clearafter
	rm -f tp1
