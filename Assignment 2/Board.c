// Name: Jack Palmstrom       ccc username: jnpalmstrom

// --------------------------- Header Files --------------------------------------- //

#include "Life.h"
#include <stdio.h>

// ------------------------ printTable Function------------------------------------ //

void printTable(TableStruct table) {
    int height, width;

        for (height = 0; height < y; height++) {
            for (width = 0; width < x; width++) {
                    if (table[height][width] == LIFE_YES) {
                        printf("X");
                    }
            else {
                        printf("O");
                    }
            }
            printf("\n");
        }
        printf("\n");
}

// ------------------------ clearTable Function------------------------------------ //

void clearTable(TableStruct table) {
    int height, width;

        for (height = 0; height < y; height++) {
            for (width = 0; width < x; width++) {
                    table[height][width] = LIFE_NO;
            }
        }
}
