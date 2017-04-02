// Name: Jack Palmstrom            ccc username: jnpalmstrom

//------------------------ Header Files ----------------------------------------- //
#include "Main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
//------------------------------------------------------------------------------- //


int main(int argc, char *argv[])
{

  unsigned trace = 0;       /* terse */

  output = fopen(argv[1], "w");

  for (int i = 2; i < argc; i++) {

	  input = fopen(argv[i], "r");

	  if (input == NULL) {
		  trace = 0;
		  int err = usage(argv[i],"Input file not found");
		  fclose(input);
		  return err;
	  }

	  trace = 1;
	  fprintf(output, "Distinct words: " "%lu\n", AllWords(input, trace));
	  fclose(input);
  }
  fclose(output);
  return 0;
}
