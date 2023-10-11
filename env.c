#include "main.h"

/**
 * _env - prints current environment
 *
 * Return: nothing
 */
void _env(void)
{
	char **env = environ;

	for (; *env != NULL; ++env)
	{
		printf("%s\n", *env);
	}
}
