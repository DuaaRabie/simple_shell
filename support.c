#include <stdio.h>

/**
 * _strlen - count the string length
 * @str: string pointer
 * Return: length
 */
unsigned int _strlen(char *str)
{
	unsigned int count = 0;

	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

