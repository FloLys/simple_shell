#include "main.h"

int main(void)
{
	char *buffer = NULL, *fullpath = NULL, *fullpathaux = NULL, *err = NULL;
	char *env = NULL;
	size_t bufsize = 1024;
	int characters = 0, i = 0, flag = 0, status = 0;
	char **index = NULL, **path = NULL;
	pid_t child_pid;
	struct stat st;

	env = _getenv("PATH");
	if (env[0] == '\0')
		exit(0);
	path = token_to_av(env, ":");
	if (path == NULL)
		exit(0);
	buffer = (char *)_calloc(bufsize, sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	while (1)
	{
		if (isatty(0))
			write(1, "$ ", 3);
		characters = getline(&buffer, &bufsize, stdin);
		if (characters == -1)
		{
			break;
		}
		index = token_to_av(buffer, " ");

		if (index[0][0] == '/')
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
			if (stat(fullpath, &st) != 0 || index[0][1] == '\0')
			{
				err = _strcat("$: ", index[0]);
				perror(err);
				free(index);
				free(err);
				flag = 2;
			}
		}
	/*slash case bin ls*/
		if (flag == 0)
		{
			if (stat((index[0]), &st) != 0 || index[0][1] == '\0')
			{
				err = _strcat("$: ", index[0]);
				perror(err);
				free(err);
				flag = 2;
			}

		child_pid = fork();
		if (child_pid == 0)
		{
			execve(index[0], index, NULL);
			exit(EXIT_SUCCESS);

			if (stat((index[0]), &st) != 0)
			{
				exit(EXIT_FAILURE);
			}
		}
		wait(&status);
		free(index);
		}
	/*not slash only ls*/
		if (flag == 1)
		{
		child_pid = fork();
			if (child_pid == 0)
			{
				execve(fullpath, index, NULL);
				exit(EXIT_SUCCESS);
				if (stat(fullpath, &st) != 0)
				{
				exit(EXIT_FAILURE);
				}
			}
		wait(&status);
		free(index);
		}
	}
	free(env);
	free(fullpath);
	free(path);
	free(buffer);
	if (isatty(0))
		write(1, "exit\n", 6);
	return (WEXITSTATUS(status));
}
