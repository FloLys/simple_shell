#include "main.h"

int main(void)
{
	char *buffer;
	char eof[4]="EOF";
	char end[12]="end-of-file";
	size_t bufsize = 32;
	int characters, i = 0, j = 0;
	char **index = NULL;
	pid_t child_pid;
	char *path1 = NULL;
	char **path2 = NULL;
	struct stat st;

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
		path1 = _getenv("PATH");
	/*	printf("%s\n", path1);*/
/*	 	path2 = token_to_av(path1, ":"); */
		
	      /* printf("%s\n", path2[0]);	*/

	/*	if (index[0][0] != '/')
		{
			while ( stat(path[i], &st_mode S_IFDIR) != 0)
			{
					i++;
			}

			if (stat(path[i], &st) == 0)
			{
				for (j = 0; path[i][j] != '\0'; j++);
				_strcat(path[i], "/");
				_strcat(path[i], index[0]);
			}
		} */
		
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error:");
			exit(1);
		}

		if (child_pid == 0)
		{
			execve(index[0], index, NULL);
			exit;
		}
		wait(NULL);	

		if (strncmp(buffer, end, 11) == 0 || strncmp(buffer, eof, 3) == 0 || buffer == 0)
			break;
		
	}

	free (buffer);
	return (0);	

}
