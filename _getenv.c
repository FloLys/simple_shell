#include "main.h"

/**
* _getenv - gets from external environ index the corresponding to input
* @var: environment to check in
* Return: string path or null otherwise
*/
char *_getenv(const char *var)
{
	char *path = NULL;
	int i = 0, j = 0, a = 0, flag = 0, auxj = 0;

	for (i = 0; *environ[i] != '\0'; i++)
	{
		for (j = 0; var[j] != '\0'; j++)
		{
			if (environ[i][j] != var[j])
			{
				flag = 0;
				break;
			}
			else
				flag = 1;
		}
		if (flag == 1)
		{
			if (environ[i][j] == '=')
			{
				auxj = j + 1;
				for (; environ[i][j + 1] != '\0'; j++)
				;
				path = _calloc(sizeof(char), (j + 1));
				if (path == NULL)
					exit(1);

				for (; environ[i][auxj] != '\0'; auxj++)
				{
					path[a] = environ[i][auxj];
					a++;
				}
				return (path);
			}
		}
	}
	free(path);
	return (NULL);
}
