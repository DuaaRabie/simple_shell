#include "main.h"

/**
 * exit_check - exit the shell
 * @argv: arguments vector
 * @cmd: command
 * Return: -1 for exit || 0
 */
int exit_check(char **argv, char *cmd)
{
	if (argv[0][0] == 'e' && argv[0][1] == 'x')
	{
		if (argv[0][2] == 'i' && argv[0][3] == 't')
		{
			free_all(argv, cmd, NULL);
			return (-1);
		}
	}

	return (0);
}
