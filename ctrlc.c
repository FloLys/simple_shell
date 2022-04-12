#include "main.h"

void ctrlc(int sig_num)
{
	if (sig_num == SIGINT)
		write(1, "\n$ ", 3);
}
