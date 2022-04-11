#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *buffer;
    char eof[4]="EOF";
    char end[12]="end-of-file";
	size_t bufsize = 32;
    size_t characters;

    buffer = (char *)malloc(bufsize * sizeof(char));
    if( buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }

    while (strncmp(buffer, eof,3)!=0) 
    {
	    printf("SS$: ");
	    characters = getline(&buffer,&bufsize,stdin);

	    if (strncmp(buffer, end, 11) == 0 || buffer == 0 || characters == -1)
		    break;	   
    }
    free (buffer);
    return(0);
}
