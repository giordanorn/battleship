.PHONY: build all clean

all: build

build: battleship

player.o: player.c
	gcc -c player.c -o player.o

ia.o: ia.c
	gcc -c ia.c -o ia.o

battleship: main.c player.o ia.o
	gcc main.c player.o ia.o -o battleship

clean:
	rm -f player.o ia.o