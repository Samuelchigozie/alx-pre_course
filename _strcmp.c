#include "shell.h"
/**
* _strcmp - compares two strings
* @s1: first string
* @s2: second string
* Return: returns (0) if the two strings are the same else (-1)
*/
int _strcmp(char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}


