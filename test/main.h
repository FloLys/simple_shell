#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void);
char **getline_token(void);
char **token_to_av(char *str, char *delim);
int token_cn(char *str, char *delim);

#endif
