#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"
/**
* _getline - reads from a command and saves it in the line)
* @line: pointer to character pointer
* @n: number of bytes
* @ptr: pointer to the file of input (usually stdin)
* Return: returns a pointer (success) NULL (faliure)
*/

char *_getline(char **cmd, size_t *n, FILE *ptr)
{
	static char buffer[1024];
	static size_t buffer_size;
	size_t len = 0;
	char *p = NULL;

*cmd = NULL;
*n = 0;

while (fgets(buffer, sizeof(buffer), ptr) != NULL)
{
	len = strlen(buffer);

	if (len > buffer_size)
	{
		buffer_size = len;
		p = (char *)realloc(*cmd, buffer_size);
		if (p == NULL)
		{
			free(*cmd);
			return (NULL);
		}
		*cmd = p;
		*n = buffer_size;
	}

memcpy(*cmd + *n - buffer_size, buffer, len);
buffer_size -= len;

	if (buffer[len - 1] == '\n')
	{
		(*cmd)[*n - 1] = '\0';
		return (*cmd);
	}
}

	if (*n > 0)
	{
		(*cmd)[*n - buffer_size] = '\0';
		return (*cmd);
	}
	else
	{
		return (NULL);
	}
}

