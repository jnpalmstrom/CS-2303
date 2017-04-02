 // Name: Jack Palmstrom       ccc username: jnpalmstrom


// Constants
#define LIFE_YES 'X'
#define LIFE_NO 'O'

// Header Files
#include <stdio.h>

// Variables
int k, x, y, gens;
typedef int **TableStruct;

// Functions
void printTable(TableStruct table);
void clearTable(TableStruct table);
void calculate(TableStruct table);
void loadTestData(TableStruct table);
int main(int argc, char *argv[]);
void PlayOne(int **tableA);
