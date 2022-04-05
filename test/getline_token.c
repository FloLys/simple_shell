#include "main.h"

int main(void)
{
	char **index = NULL;
	int i;

	index = getline_token();

	for (i = 0; index[i] != NULL; i++)
		printf("%s\n", index[i]);	

	return(0);
}

char **getline_token(void)
{
	char *buffer;
	char eof[4]="EOF";
	char end[12]="end-of-file";
	size_t bufsize = 32;
	int characters = 0;
	char **index = NULL;

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

		if (characters == -1 || strncmp(buffer, end, 11) == 0 || strncmp(buffer, eof, 3) == 0 || buffer == 0)
			break;
		index = token_to_av(buffer, " ");

		return (index);
	}

	free (buffer);
	return(NULL);
}
