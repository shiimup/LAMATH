SHELL = /bin/sh

CC = gcc
CFLAGS = -lm

SRC = main.c matrix.c integral.c numerical_diff.c ode.c
OBJ = $(SRC:.c=.o)
P_OBJ=$(addprefix build/,$(SRC:.c=.o))
DEBUG_OBJ = $(SRC:.c=_debug.o)
P_DEBUG_OBJ=$(addprefix build/,$(SRC:.c=_debug.o))

all: main debug

main: $(OBJ)
	$(CC) -O2 -Wall $(P_OBJ) -o build/$@ $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o build/$@

debug: $(DEBUG_OBJ)
	$(CC) -Wall $(P_DEBUG_OBJ) -o build/$@ $(CFLAGS)

%_debug.o: %.c
	gcc -Wall $(CFLAGS) -c -g $^ -o build/$@

clean:
	rm -f build/*

.PHONY: clean all
