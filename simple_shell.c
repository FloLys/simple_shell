#include "main.h"

int main(void)
{
	char *buffer = NULL, *fullpath = NULL, *fullpathaux = NULL;
	char *env = NULL;
	size_t bufsize = 1024;
	int characters = 0, i = 0, flag = 0, status = 0;
	char **index = NULL, **path = NULL;
	pid_t child_pid;
	struct stat st;

	env = _getenv("PATH");
	path = token_to_av(env, ":");
	free(env);
	buffer = (char *)_calloc(bufsize, sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 5);
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == -1)
		{
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
				perror("not found");
				free(index);
				flag = 2;
			}
		}
	/*slash case bin ls*/
		if (flag == 0)
		{
			if (stat(index[0], &st) != 0)
			{
				perror("not found");
			}
	
		child_pid = fork();
		if (child_pid == 0)
		{
			execve(index[0], index, NULL);
			exit(0);
		}
		wait(NULL);
		free(index);
		}
	/*not slash only ls*/
		if (flag == 1)
		{
		child_pid = fork();
			if (child_pid == 0)
			{
				execve(fullpath, index, NULL);
				exit(0);
			}
		wait(&status);
		free(index);
		}
	}
	free(fullpath);
	free(path);
	free(buffer);
	if (isatty(0))
		write(1, "exit\n", 5);
	exit(2);
}
