// Name: Jack Palmstrom            ccc username: jnpalmstrom

#ifndef TREE_H_
#define TREE_H_
#define WORDCHUNK 9

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct WordTree {
  struct WordTree *below, /* words that come before this word */
                  *above; /* words that come after this word  */
  char *word;
  unsigned long used;
};

FILE *input, *output;
unsigned long total;
void lower_string(char s[]);
char *GetWord(FILE *input);
int AddWord(char *text, struct WordTree **base);
void DelWord(struct WordTree *root, int trace);
unsigned long AllWords(FILE *input, int trace);
int usage(char *name, char *text);

#endif /* TREE_H_ */
