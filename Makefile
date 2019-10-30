.PHONY: build all clean

all: build

build: battleship

battleship: battleship.c utils.o
	gcc battleship.c utils.o -o battleship

utils.o: utils.c
	gcc -c utils.c -o utils.o

clean:
	rm -f utils.o
	rm -f battleship
