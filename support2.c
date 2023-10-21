#include "main.h"

/**
 * _strncmp - compare two strings
 * @s1: pointer to first string
 * @s2: pointer to second string
 * @n: size to compare
 * Return: 0 equal
 * negative value if s1 is less than s2
 * positive value if s1 is greater than s2
 */
int _strncmp(char *s1, char *s2, int n)
{
	int dif = 0;
	int i = 0;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
		{
			dif = s1[i] - s2[i];
		}
	}

	return (dif);
}

/**
 * _strcmp - compare two strings
 * @s1: pointer to first string
 * @s2: pointer to second string
 * Return: 0 equal
 * negative value if s1 is less than s2
 * positive value if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int dif = 0;
	int i = 0;

	for (; (s1[i] != '\0' || s2[i] != '\0'); i++)
	{
		if (s1[i] == s2[i])
			continue;
		else
			break;
	}

	dif = s1[i] - s2[i];

	return (dif);
}

#include "main.h"

/**
 * _memcpy - copies memory area
 * @dest: starting address to copy memory to
 * @src: starting address to copy memory from
 * @n: the number of bytes to be copied
 * Return: the copied to address
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		*(dest + i) = *(src + i);
	}

	return (dest);
}
