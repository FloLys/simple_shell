#include "main.h"

int main(void)
{
	char *buffer = NULL, *fullpath = NULL, *fullpathaux = NULL;
	char *env = NULL;
	char eof[4]="EOF";
	char end[12]="end-of-file";
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
		free(path);
		exit(1);
	}

	while (characters != -1)
	{
		printf("SS$: ");
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
				fullpathaux = _strcat(path[i], "/");
				fullpath = _strcat(fullpathaux, index[0]);
				free(fullpathaux);

				if (stat(fullpath, &st) == 0)
				{
					flag = 2;
					break;
				
				}
				
			}
			if (stat(fullpath, &st) != 0)
			{
			perror("command not found");
			flag = 1;
			}
		}
		

		if (flag == 0 || flag == 2)
		{
		/*	if (flag == 1)
			{
				if (stat(fullpath, &st) != 0)
				{
					perror("command not found");
					free(fullpath);
				
						
				}
			}*/

			if (flag == 0)
			{
				fullpath = index[0];
				if (stat(fullpath, &st) != 0)
				{
					perror("command not found");
					free(fullpath);
					
					
				}
			}


			child_pid = fork();

			if (child_pid == 0)
			{
				execve(fullpath, index, NULL);
				exit(0);
			}
			wait(NULL);
			free(index);

			if (strncmp(buffer, end, 11) == 0 || strncmp(buffer, eof, 3) == 0 || buffer == 0)
			{
				free(fullpath);
				free(index);
				break;
			
			}
			}
		
	}
	free(path);
	free(buffer);
	return (0);	

	}

