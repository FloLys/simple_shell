#include "main.h"

int main(void)
{
	char *buffer, *fullpath = NULL;
	char eof[4]="EOF";
	char end[12]="end-of-file";
	size_t bufsize = 32;
	int characters, i, flag;
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
				fullpath = _strcat(path[i], "/");
			//	printf("%s\n", fullpath);
				fullpath = _strcat(fullpath, index[0]);
			//	printf("%s\n", fullpath);

				if (stat(fullpath, &st) == 0)
				{
			//		printf("PROGRAM FOUND\n");
					flag = 1;
					break;
				}
			/*	else
				{
					printf("NOT FOUND\n");
				}*/
			}
		}
		flag = 0;

		if (flag == 1 || flag == 0)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
				exit(1);
			}

			if (child_pid == 0)
			{
				execve(fullpath, index, NULL);
				exit(0);
			}
			wait(NULL);	

			if (strncmp(buffer, end, 11) == 0 || strncmp(buffer, eof, 3) == 0 || buffer == 0)
				break;
		}
	}

	free (buffer);
	return (0);	
}
