SHELL = /bin/sh

main: main.o matrix.o integral.o
	gcc -lm build/main.o build/matrix.o build/integral.o -o build/main

main.o: main.c
	gcc -static -lm -c main.c -o build/main.o

matrix.o: matrix.c
	gcc -static -lm -c matrix.c -o build/matrix.o

integral.o: integral.c
	gcc -static -lm -c integral.c -o build/integral.o

debug: debug_main.o debug_matrix.o debug_integral.o
	gcc -lm build/debug_main.o build/debug_matrix.o build/debug_integral.o -o build/debug

debug_main.o: main.c
	gcc -lm -c -g main.c -o build/debug_main.o

debug_matrix.o: matrix.c
	gcc -lm -c -g matrix.c -o build/debug_matrix.o

debug_integral.o: integral.c
	gcc -lm -c -g integral.c -o build/debug_integral.o

clean:
	rm -f build/*
