#include "main.h"

/**
 *_strlen - count the string length
 *@str: string pointer
 *Return: length
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

/**
 *_strcpy - copis the string including termination
 *@src: pointer of a string
 *@dest: pointer of buffer
 *Return: nothing
 */
char *_strcpy(char *dest, char *src)
{
	int count;
	int length = 0;

	for (count = 0; src[count] != '\0'; count++)
	{
		length += 1;
	}
	for (count = 0; count <= length; count++)
	{
		dest[count] = src[count];
	}
	return (dest);
}

/**
 *_strcat - concatenates two strings
 *@dest: pointer to first string
 *@src: ponter to second string
 *Return: pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
	int total_length;
	int l1, l2;
	int i;
	int j = 0;

	l1 = _strlen(dest);
	l2 = _strlen(src);
	total_length = l1 + l2;
	for (i = l1; i < total_length; i++)
	{
		dest[i] = src[j];
		j++;
	}
	return (dest);
}
