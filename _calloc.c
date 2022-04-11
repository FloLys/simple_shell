#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * _calloc - allocate memory for an array using malloc
 * @nmemb: number of elements of size[] bytes each, row
 * @size: number of elements in each nmemb byte, column
 * Return: pointer to the allocated memory
*/
void *_calloc(size_t nmemb, size_t size)
{
	unsigned int i;
	char *a;

	if (nmemb == 0 || size == 0)
		return (NULL);

	a = malloc(nmemb * size);

	if (a == NULL)
		return (NULL);

	for (i = 0; i < nmemb * size; i++)
		a[i] = 0;

	return (a);
}
