#include "main.h"

/**
 * built_cmd - exit the shell
 * @argv: arguments vector
 * @cmd: command
 * Return: -1 for exit || 0
 */
int built_cmd(char **argv, char *cmd)
{
	char *copy = _strdup(cmd);

	if (strtok(copy, " \n") == NULL)
	{
		free_all(argv, cmd, copy);
		return (2);
	}
	free(copy);

	if (argv[0][0] == 'e' && argv[0][1] == 'x'
			&& argv[0][2] == 'i' && argv[0][3] == 't'
			&& argv[0][4] == '\0')
		exit_fun(argv, cmd);
	if (argv[0][0] == 'e' && argv[0][1] == 'n' && argv[0][2] == 'v'
			&& argv[0][3] == '\0')
	{
		free_all(argv, cmd, NULL);
		_env();
		return (1);
	}
	if (argv[0][0] == 'u' && argv[0][1] == 'n' && argv[0][2] == 's'
			&& argv[0][3] == 'e' && argv[0][4] == 't'
			&& argv[0][5] == 'e' && argv[0][6] == 'n'
			&& argv[0][7] == 'v' && argv[0][8] == '\0')
	{
		_unsetenv(argv[1]);
		free_all(argv, cmd, NULL);
		return (1);
	}
	if (argv[0][0] == 's' && argv[0][1] == 'e' && argv[0][2] == 't'
			&& argv[0][3] == 'e' && argv[0][4] == 'n'
			&& argv[0][5] == 'v' && argv[0][6] == '\0')
	{
		_setenv(argv[1], argv[2], 1);
		free_all(argv, cmd, NULL);
		return (1);
	}
	return (0);
}
