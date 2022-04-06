#include "main.h"

int main(void)
{
	char *buffer;
	char eof[4]="EOF";
	char end[12]="end-of-file";
	size_t bufsize = 32;
	int characters, i = 0;
	char **index = NULL;
	char *cmd = "/bin/";
	/*char *av[];*/
	/*char *env[] = {"/bin", NULL};*/
	pid_t child_pid;

	/*buffer = (char *)malloc(bufsize * sizeof(char));*/
	if(buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	while (characters != -1)
	{
		printf("SS$: ");
		characters = getline(&buffer, &bufsize, stdin);
		index = token_to_av(buffer, " ");

		child_pid = fork();
	
	if (child_pid == -1)
	{
		perror("Error:");
		exit(1);
	}
	
	if (child_pid == 0)
	{
	/*	av[index] = *index; */
		execve(index[0], index, NULL);
		return (0);
	}
	wait(NULL);	

		if (strncmp(buffer, end, 11) == 0 || strncmp(buffer, eof, 3) == 0 || buffer == 0)
			break;
	}

	free (buffer);
	
	
}
