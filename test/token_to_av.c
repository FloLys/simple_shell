#include "main.h"

/**
* token_to_av - places the number of words size in an index null terminated
* @str: string
* @delim: character or string delimiter of words
* Return: the array of strings (words) used in input (index)
*/
char **token_to_av(char *str, char *delim)
{
	char **index = NULL;
	char *token = NULL;
	int i, size, enter;

	size = token_cn(str, delim);

	index = malloc((size + 1) * sizeof(char *));
	if (index == NULL)
	{
		perror("Unable to allocate");
		exit(1);
	}

	token = strtok(str, delim);

	for (i = 0; token; i++)
	{
		index[i] = token;
		token = strtok(NULL, delim);
	}
	index[i] = NULL;

	for (enter = 0; index[i - 1][enter] != '\n'; enter++)
	{
		if (index[i - 1][enter] == '\0')
		{
			break;
		}
	}

	index[i - 1][enter] = '\0';

	return (index);
}
/**
* token_cn - counts the number of times a word is found by its delimiter
* @str: string
* @delim: delimitator of words
* Return: number of words will be the size of array index
*/
int token_cn(char *str, char *delim)
{
	int i, size = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == delim[0])
			size++;
	}

	return(size);
}
