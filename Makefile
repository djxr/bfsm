CC=cc
CFLAGS=-std=c99 -Wall -g -pedantic
LDFLAGS=-lSDL2

all: badfsm

run:
	./badfsm

clean:
	rm -f badfsm 
