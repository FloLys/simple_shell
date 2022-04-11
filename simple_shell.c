#include "main.h"

int main(void)
{
	char *buffer = NULL, *fullpath = NULL, *fullpathaux = NULL;
	char *env = NULL;
	size_t bufsize = 32;
	int characters = 0, i, flag;
	char **index = NULL, **path = NULL;
	pid_t child_pid;
	struct stat st;

	env = _getenv("PATH");
	path = token_to_av(env, ":");
	free(env);
	buffer = (char *)malloc(bufsize * sizeof(char));
	if(buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	while (characters != -1)
	{
		printf("SS$: ");
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == -1)
		{
		/*	free(fullpath);*/
			break;
		}
		index = token_to_av(buffer, " ");

		flag = 0;
		if (index[0][0] != '/')
		{
			for (i = 0; path[i] != NULL; i++)
			{
				free(fullpath);
				fullpathaux = _strcat(path[i], "/");
				fullpath = _strcat(fullpathaux, index[0]);
				free(fullpathaux);

				if (stat(fullpath, &st) == 0)
				{
					flag = 1;
					break;
				}
			}
			if (stat(fullpath, &st) != 0)
			{
				perror("Command not found");
				free(index);
				flag = 2;
			}
		}

		if (flag == 0 || flag == 1)
		{
			if (flag == 0)
			{
				if (stat(index[0], &st) != 0)
				{
					perror("Command not found");
				}
			}

			child_pid = fork();
			if (child_pid == 0)
			{
				execve(fullpath, index, NULL);
				exit(0);
			}
			wait(NULL);
		/*	free(index);*/
		/*	free(fullpath);*/
		}
	}
/*	free(index);*/
	free(fullpath);
	free(path);
	free(buffer);
	printf("exit\n");
	return (0);
}
