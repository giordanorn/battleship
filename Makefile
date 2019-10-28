.PHONY: build all clean

all: build

build: battleship

battleship: battleship.c utils.o game.o
	gcc battleship.c utils.o game.o -o battleship

utils.o: utils.c
	gcc -c utils.c -o utils.o

game.o: game.c
	gcc -c game.c -o game.o

clean:
	rm -f utils.o game.o
	rm -f battleship
