#include "main.h"
#define CHILDPIDS 5
#include <sys/wait.h>
/**
*
*
*/
int main(void)
{
	int i;
	char *cmd = "/bin/ls";
	char *av[] = {"ls", "-l", "/tmp", NULL};
	char *env[] = {"/bin/ls", NULL};
	pid_t child_pid;

	for (i = 0; i < CHILDPIDS; i++)
	{
	child_pid = fork();
	printf("pid: %u\n", getpid());
	
	if (child_pid == -1)
	{
		perror("Error:");
		exit(1);
	}
	
	if (child_pid == 0)
	{
		printf("im a child: %u\n", getpid());
		execve(cmd, av, env);
		return (0);
	}
	wait(NULL);
	}

	return (0);
}
