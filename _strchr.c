#include "shell.h"
/**
* _strchr - returns the pointer to the first maths
* of a character in str
* @s: the string to be parsed
* @c: the character we are looking for
* Return: returns char * on succes and NULL on failure to find a match
*/
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *) s);
		}
		s++;
	}
	return (NULL);
}
