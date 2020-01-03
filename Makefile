# Makefile for hw1

hw1: main.o formatPicture.o readFile.o hw1given.o
	gcc -O0 -std=c11 -pedantic -Wall -g main.c formatPicture.c readFile.c hw1given.c -lm -o hw1

clean: 
	rm -f *.0 hw1
