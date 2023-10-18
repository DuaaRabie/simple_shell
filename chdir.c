#include "main.h"

/**
 * _cd - change directory
 * @dir: directory
 * Return: nothing
 */
void _cd(char *dir, char **argv, char **av)
{
	if (chdir(dir) != 0)
		print_error('d', argv, av);
}
