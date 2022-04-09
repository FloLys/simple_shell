#include "main.h"

int main(void)
{
	char *buffer;
	char eof[4]="EOF";
	char end[12]="end-of-file";
	size_t bufsize = 32;
	int characters;
	char **index = NULL, **path = NULL;
	pid_t child_pid;
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
		path = token_to_av(_getenv("PATH", ":"));

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
