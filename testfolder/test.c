#include "main.h"

int main(void)
{
	char s[60] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
	char **s2 = NULL;
	int i = 0;

	s2 = token_to_av(s, ":");

	while (s2[i] )
	printf("%s\n", token));
	return(0);
}
