main: main.o
	gcc build/main.o -o build/main

main.o: main.c
	gcc -c main.c -o build/main.o

clean:
	rm -f build/*

debug: debug.o
	gcc build/debug.o -o build/debug

debug.o: main.c
	gcc -c -g main.c -o build/debug.o
