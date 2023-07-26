main: main.o
	gcc build/main.o -o build/main

main.o: main.c
	gcc -c main.c -o build/main.o

clean:
	rm -f build/*
