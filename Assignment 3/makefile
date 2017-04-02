# Name: Jack Palmstrom    ccc username: jnpalmstrom

# This makefile is used as follows to regenerate files for the life program:
#   make Main.o       --  Regenerates Main.o by compiling
#   make Tree.o       --  Regenerates Tree.o by compiling

#   make PA3          --  Regenerates the executable life file by compiling
#   make              --  Same as "make PA3"


CFLAGS = -g

PA3: Main.o Tree.o 
	gcc $(CFLAGS) -Wall Main.o Tree.o -lm -o PA3

Main.o: Main.h Main.c 
	gcc $(CFLAGS) -Wall -c Main.c

Tree.o: Tree.h Tree.c 
	gcc $(CFLAGS) -Wall -c Tree.c
	
clean:
	rm -f Main.o Tree.o PA3

all: PA3

     
     