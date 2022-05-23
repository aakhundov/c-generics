all: bin
	gcc -std=c99 *.c -o ./bin/generics

bin:
	mkdir ./bin
