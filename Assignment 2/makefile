# Name: Jack Palmstrom    ccc username: jnpalmstrom

# This makefile is used as follows to regenerate files for the life program:
#   make Life.o       --  Regenerates Life.o by compiling
#   make Game.o       --  Regenerates Game.o by compiling
#   make Board.o      --  Regenerates Board.o by compiling
#   make life         --  Regenerates the executable life file by compiling
#   make              --  Same as "make life"


CFLAGS = -g

life: Life.o Game.o Board.o
	gcc $(CFLAGS) -Wall Life.o Game.o Board.o -lm -o life

Life.o: Life.c Life.h
	gcc $(CFLAGS) -Wall -c Life.c

Game.o: Game.c Life.h
	gcc $(CFLAGS) -Wall -c Game.c
	
Board.o: Board.c Life.h
	gcc $(CFLAGS) -Wall -c Board.c	

clean:
	rm -f Life.o Game.o Board.o life

all: life
