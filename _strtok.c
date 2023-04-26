#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* _strtok - tokenizes a string
* @str: string to be tokenized
* @delim: delimiter
* Return: returns a character pointer to token or NULL
*/
char *_strtok(char *str, const char *delim)
{
	static char *endoftoken;
	char *token = NULL;

	if (str != NULL)
	{
		endoftoken = str;
	}

	while (*endoftoken != '\0' && _strchr(delim, *endoftoken) != NULL)
	{
		endoftoken++;
	}

	if (*endoftoken == '\0')
	{
		return (NULL);
	}

	token = endoftoken;

	while (*endoftoken != '\0' && _strchr(delim, *endoftoken) == NULL)
	{
		endoftoken++;
	}

	if (*endoftoken != '\0')
	{
		*endoftoken = '\0';
		endoftoken++;
	}
	return (token);
}

