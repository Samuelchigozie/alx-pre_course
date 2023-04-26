#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* exit_shell - this exit with an exit status
* @args: the pointer to character array
* gotten from the command line
* Return: returns (void)
*/
void exit_shell(char *args[])
{
	int exit_status = 0;

	printf("%s  %s", args[0], args[1]);
	if (args[1] != NULL)
	{
		exit_status = atoi(args[1]);
	}
	exit(exit_status);
}
