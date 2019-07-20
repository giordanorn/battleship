.PHONY: build all clean

all: build

build: battleship

utils.o: utils.c
	gcc -c utils.c -o utils.o

battleship: main.c utils.o
	gcc main.c utils.o -o battleship

clean:
	rm -f utils.o
	rm -f battleship