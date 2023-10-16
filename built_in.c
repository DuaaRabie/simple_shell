#include "main.h"

/**
 * built_cmd - exit the shell
 * @argv: arguments vector
 * @cmd: command
 * Return: -1 for exit || 0
 */
int built_cmd(char **argv, char *cmd)
{
	if (argv[0][0] == 'e' && argv[0][1] == 'x'
			&& argv[0][2] == 'i' && argv[0][3] == 't')
		exit_fun(argv, cmd);

	if (argv[0][0] == 'e' && argv[0][1] == 'n' && argv[0][2] == 'v')
	{
		free_all(argv, cmd, NULL);
		_env();
		return (1);
	}

	return (0);
}
