#include "main.h"
#include <sys/wait.h>

int execve(char *const pathname[], char *const argv[], char *const envp[])
{
	int i;
	char *pathname[] = {"/bin/ls", NULL};
	char *av[] = *index;
	char *envp[] = {"/bin/ls", NULL};
	pid_t child_pid;

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
		execve(pathname, av, envp);
		return (0);
	}
	wait(NULL);
	}

	return (0);
}
