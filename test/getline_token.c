#include "main.h"

int main(void)
{
	char *buffer, *str = NULL;
	char eof[4]="EOF";
	char end[12]="end-of-file";
	size_t bufsize = 32;
	int characters, i;
	char **index = NULL, **path = NULL;
	pid_t child_pid;
	struct stat st;

	path = token_to_av(_getenv("PATH"), ":");
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
			break;

		index = token_to_av(buffer, " ");

		if (index[0][0] != '/')
		{
			for (i = 0; path[i] != NULL; i++)
			{	
				str = NULL;
				str = _strcat(path[i], "/");
				printf("%s\n", str);
				str = _strcat(str, index[0]);
				printf("%s\n", str);

				if (stat(str, &st) == 0)
				{
					printf("program found\n");
				}
				else
				{
					printf("not found\n");
					;
				}
			}
		}

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			exit(1);
		}

		if (child_pid == 0)
		{
			execve(index[0], index, NULL);
			exit(0);
		}
		wait(NULL);	

		if (strncmp(buffer, end, 11) == 0 || strncmp(buffer, eof, 3) == 0 || buffer == 0)
			break;
	}

	free (buffer);
	return (0);	
}
