#include "main.h"

char *_getpath(void)
{
	char **path = NULL;
	char *str;
	struct stat st;
	int i;

	path = token_to_av(_getenv("PATH"), ":")

	for (i = 0; path[i] != '\0'; i++)
	{
		if (stat(path[0], ) == 0)
		{
			printf("%s\n", path);
			strncat(str, );
		}
	}
	return (path);
