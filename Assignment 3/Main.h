/*
 * Main.h
 *
 *  Created on: Feb 6, 2017
 *      Author: student
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
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


#endif /* MAIN_H_ */
