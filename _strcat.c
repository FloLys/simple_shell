#include "main.h"

/**
 * _strcat - concatenates two strings with malloc
 * @dest: destination string
 * @src: source string
 * Return: complete string
 */
char *_strcat(char *dest, char *src)
{
	char *strcat;
	int destSize = 0;
	int srcSize = 0;
	int a;

	while (dest[destSize] != '\0')
		destSize++;

	while (src[srcSize] != '\0')
		srcSize++;

	strcat = malloc(sizeof(char) * (destSize + srcSize));

	for (a = 0; a <= destSize; a++)
		strcat[a] = dest[a];

	for (a = 0; a <= srcSize; a++)
		strcat[destSize + a] = src[a];

	return (strcat);
}
