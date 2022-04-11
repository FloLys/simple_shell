#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t fc, sc;
    int status;
    char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

    fc = fork();
    sc = fork();
    if (fc == -1 || sc == -1)
    {
        perror("Error:");
        return (1);
    }
    if (fc > 0 && sc > 0) 
    {
	    waitpid(fc, &status, 0);
	    printf("I am your father\n");
	    execve(argv[0], argv, NULL);
    }
    else if (fc == 0 && sc > 0)
    {
	    waitpid(sc, &status, 0);
	    printf("first child\n");
	   execve(argv[0], argv, NULL);
    }
    else if (fc > 0 && sc == 0)
    {
	   execve(argv[0], argv, NULL);
	   printf("second child\n");
           execve(argv[0], argv, NULL);
    }
/*    else
    {
	   printf("third child\n");
           execve(argv[0], argv, NULL);
    }*/
	    return (0);
}
