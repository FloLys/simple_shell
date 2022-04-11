#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
int main(void);
char **token_to_av(char *str, char *delim);
int token_cn(char *str, char *delim);
char *_getenv(const char *var);
char *_strcat(char *dest, char *src);
void *_calloc(size_t nmemb, size_t size);
#endif
