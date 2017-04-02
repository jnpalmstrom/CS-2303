Name: Jack Palmstrom
Date: 1/30/2017
Class: CS2303
Professor: Lauer

Summary of Program:

	The Program is John Conway's The Game of Life. The game is played on a rectangular grid of cells, so that each cell has eight neighbors. Each cell is either occupied by an 		organism or not. A pattern of occupied and unoccupied cells in the grid is called a generation. If an occupied cell has 0, 1, 4, 5, 6, 7, or 8 occupied neighbors, the 		organism dies. If the organism has has 2 or 3 neighbors, the organism survives. If an unoccupied cell has precisely 3 occupied neighbors, it becomes occupied by a new 		organism. The game ends when either all the organisms die, the pattern of organisms repeats itself from a previous generation, or a predefined number of generations is met.


How to Run the Program:

	The program does not run correctly. I was able to create a makefile that allows life to be created and make all to run as well as making each partitions .o file. The 		makefile also allows clean to work properly. The program compiles with no warnings in Eclipse for me, but does not allow to be run from the command line.

Details of Problems:

	The two major problems I had with this assignment was being able to invoke commands from the command line, arrays, and pointers. I struggled greatly when it came to deciding 		whether I use an array or a pointer. I don't really grasp how to allocate memory to a 2-D array. 

Cite Sources:
	
	I took the algorithms in this assignment from http://www.dreamincode.net/forums/topic/73284-the-game-of-life-in-source-c/

