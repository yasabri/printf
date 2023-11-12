#include "main.h"

/**
 * _strlen - returns the length of a string
 * @str: string pointer
 * Return: i
 */

int _strlen(char *str)
{
	int i;

	for (i = 0 ; str[i] != 0 ; i++)
		i++;
	return (i);
}

/**
 * _strlenc - returns the length of a string
 * @str: char pointer
 * Return: i
 */

int _strlenc(const char *str)
{
	int i;

	for (i = 0 ; str[i] != 0 ; i++)
		i++;
	return (i);
}
