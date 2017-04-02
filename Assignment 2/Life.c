// Name: Jack Palmstrom       ccc username: jnpalmstrom

// Life.c includes main func, reads input, and initialzes

// --------------------------- Header Files --------------------------------------- //
#include "Life.h"
#include <stdio.h>
#include <stdlib.h>

// --------------------------- main Function -------------------------------------- //
int main(int argc, char *argv[]) {

    	int **table;
    	char end;
    	int generation = 0;

	    FILE *input;
	    int i, j;
	    if (argc < 5) {
	    	printf("Not enough elements entered into command line.");
	    }

	    x = atoi(argv[1]);
	    y = atoi(argv[2]);
	    gens = atoi(argv[3]);
	    input = fopen(argv[4], "r");

	    if((input = fopen("file", "r")) == NULL) {
	    	fprintf(stderr, "Unable to open file\n");
	    	exit(1);
	    }
	    for (i = 0; i < x; i++) {
	    	for (j = 0; j < y; j++) {
	    		fscanf(input, "%d", &table[i][j]);
	    	}
	    }
	    fclose(input);


// --------------------------- Run Functions -------------------------------------------- //

		clearTable(table);
		loadTestData(table);
		printTable(table);

		for (generation = 0; generation < gens; generation++) {
		    do {
		        PlayOne(table);
		        printTable(table);
		        printf("Generation %d\n", ++generation);
		        printf("Press q to quit or 1 to continue: ");
		        scanf(" %c", &end);

		    } while (end != 'q') ;
		}

		    return 0;
		}
