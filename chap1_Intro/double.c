/*
double program : program that detects adjacent identitical words in its input
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
#include <string.h>

// Function Declaration
int getword(FILE *, char *, int);
void doubleword(char *, FILE *);

int main(int argc, char *argv[])
{
	int i;

	for(i=1; i< argc; i++){
	  FILE *fp = fopen(argv[i], "r");
	  if (fp == NULL){
		fprintf(stderr, "%s can't open '%s' (%s)\n",
			argv[0], argv[i], strerror(errorno));
	       	return EXIT_FAILURE;
	  }
	  else {
		doubleword(argv[i], fp);
		fclose(fp);
	  }
	}
	if (argc == 1) doubleword(NULL, stdin);
	return EXIT_SUCCESS;
}

int getword(File *fp, char *buf, int size){
	int c;

	c = getc(fp)
	int linenum = 0;
	//<scan forward to nonspace char or EOF 6>
	for(; c!= EOF && isspace(c); c = getc(fp))
		if (c == '\n')
			linenum ++;
	//<copy the word into buf[0.. size -1] 7>
	{
	  int i = 0; 
	  for ( ; c != EOF && !isspace(c); c = getc(fp))
		if (i < size - 1)
		  buf[i++] = tolower(c);
	       	if (i < size)
		  buf[i] = '\0';
        }
	if (c != EOF)
	  unget(c, fp);
	return buf[0] != '\0';//<found a word> 7>;
}

void doubleword(char *name, FILE *fp) {
	char prev[128], word[128];
	linenum = 1;
	prev[0] = '\0';
	while (getword(fp, word, sizeof word)) {
	  if (isalpha(word[0]) && strcmp(prev, word)==0)
	  {
	      if(name)
	        printf("%s: ", name);
	      printf("%d: %s\n", linenum, word);
	  }
	  strcpy(prev, word);
	}
}
