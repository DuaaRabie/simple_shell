#include "main.h"

/**
 * _cd - change directory
 * @dir: directory
 * @argv: command vector
 * @av: arguments vector
 * Return: nothing
 */
void _cd(char *dir, char **argv, char **av)
{
	char *pwd;

	if (dir == NULL)
		dir = getenv("HOME");

	if (chdir(dir) != 0)
		print_error('d', argv, av);
	else
	{
		pwd = getenv("PWD");
		if (pwd != NULL)
			getcwd(pwd, sizeof(pwd));
	}
}

