// Name: Jack Palmstrom       ccc username: jnpalmstrom

// --------------------------- Header Files --------------------------------------- //

#include "Life.h"
#include <stdio.h>
#include <stdlib.h>


// ---------------------- getNeighborValue Function ------------------------------- //

int getNeighborValue(TableStruct table, int row, int col) {

	    if (row < 0 || row >= y || col < 0 || col >= x || table[row][col] != LIFE_YES) {

	        return 0;

	    } else {

	        return 1;

	    }
	}

// ---------------------- getNeighborCount Function ------------------------------- //

int getNeighborCount(TableStruct table, int row, int col) {

	int neighbor = 0;

	neighbor += getNeighborValue(table, row - 1, col - 1);
	neighbor += getNeighborValue(table, row - 1, col);
	neighbor += getNeighborValue(table, row - 1, col + 1);
	neighbor += getNeighborValue(table, row, col - 1);
	neighbor += getNeighborValue(table, row, col + 1);
    neighbor += getNeighborValue(table, row + 1, col - 1);
	neighbor += getNeighborValue(table, row + 1, col);
	neighbor += getNeighborValue(table, row + 1, col + 1);

	return neighbor;
}

// -------------------------- calculate Function ---------------------------------- //

void PlayOne(int **tableA) {

	int* allocateMem(int** table) {

		unsigned int i;

		 *table = malloc(x * sizeof(int*));
		  int **table_data = malloc(x * y * sizeof(int));

		  for(i = 0; i < x; i++) {
		     table = table_data + i * y;
		  }
		     return *table; //free point

	}

	    int neighbor, height, width, table_data;

	    for (height = 0; height < y; height++) {

	        for (width = 0; width < x; width++) {

	            neighbor = getNeighborCount(tableA, height, width);

	            // change this around to remove the ? : notation

	            if (neighbor == 3) {

	                table_data = LIFE_YES;

	            } else if (neighbor == 2 && tableA[height][width] == LIFE_YES) {

	                table_data = LIFE_YES;

	            } else {

	                table_data = LIFE_NO;

	            }
	        }
	    }

	    // used to be swap

	    for (height = 0; height < y; height++) {

	        for (width = 0; width < x; width++) {

	            tableA[height][width] = table_data;

	        }
	    }
	}

	void loadTestData(TableStruct table) {

		table[3][4] = LIFE_YES;
	    table[3][5] = LIFE_YES;
	    table[3][6] = LIFE_YES;

	    // glider
	    table[10][4] = LIFE_YES;
	    table[10][5] = LIFE_YES;
	    table[10][6] = LIFE_YES;
	    table[11][6] = LIFE_YES;
	    table[12][5] = LIFE_YES;
	}
