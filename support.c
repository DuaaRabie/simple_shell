#include "main.h"

/**
 *_strlen - count the string length
 *@str: string pointer
 *Return: length
 */
unsigned int _strlen(char *str)
{
	unsigned int count = 0;
	int i = 0;

	while (str[i])
	{
		count++;
		i++;
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
	for (count = 0; count < length; count++)
	{
		dest[count] = src[count];
	}
	dest[length] = '\0';
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
	dest[total_length] = '\0';
	return (dest);
}

/**
 * _strdup - copy string by allocating memory dynamically
 * @str: string to be copied
 * Return: pointer to the copy
 */
char *_strdup(char *str)
{
	char *copy = malloc(_strlen(str) + 1);

	if (copy == NULL)
		return (NULL);

	_strcpy(copy, str);

	return (copy);
}

/**
 * *_strchr - locates a character in a string
 * @s: address to string
 * @c: the character to be located
 * Return: pointer to first occurance to c
*/
char *_strchr(char *s, char c)
{
	int length = 1;
	int i = 0;

	while (*(s + i) != '\0')
	{
		length++;
		i++;
	}

	for (i = 0; i < length; i++, s++)
	{
		if (*s == c)
		{
			return (s);
		}
	}

	return ('\0');
}
