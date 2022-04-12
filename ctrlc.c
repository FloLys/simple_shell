#include "main.h"

/**
* ctrlc - signal ctrl c
* @sig_num: number
*/
void ctrlc(int sig_num)
{
	if (sig_num == SIGINT)
		write(1, "\n$ ", 3);
}
