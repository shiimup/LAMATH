main: main.o matrix.o
	gcc build/main.o build/matrix.o -o build/main

main.o: main.c
	gcc -c main.c -o build/main.o

matrix.o: matrix.c
	gcc -c matrix.c -o build/matrix.o

clean:
	rm -f build/*

debug: debug_main.o
	gcc build/debug_main.o build/debug_matrix.o -o build/debug

debug_main.o: main.c
	gcc -c -g main.c -o build/debug_main.o

debug_matrix.o: matrix.c
	gcc -c -g matrix.c -o build/debug_main.o
