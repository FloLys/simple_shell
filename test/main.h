#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void);
/*char **getline_token(void);*/
char **token_to_av(char *str, char *delim);
int token_cn(char *str, char *delim);
/*int execve(char *const pathname[], char *const argv[], char *const envp[]); */
char *_getenv(const char *var);

#endif
