# Made by Thiago Vieira
# The option -c in gcc: Compile and assemble, but do not link
CC=gcc

all: build clearafter

build: mainExato.o mainHeuristica.o vector.o bitmask.o input.o
	$(CC) mainExato.o vector.o bitmask.o input.o -o tp2e -lm
	$(CC) mainHeuristica.o vector.o input.o -o tp2h -lm

mainHeuristica.o:
	$(CC) -c mainHeuristica.c -o mainHeuristica.o

mainExato.o: bitmask.h input.h
	$(CC) -c mainExato.c -o mainExato.o

input.o: vector.o
	$(CC) -c input.c -o input.o

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
