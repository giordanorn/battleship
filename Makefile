.PHONY: build all clean

all: build

build: battleship

battleship: main.c
	gcc main.c -o battleship

clean:
	rm -f battleship