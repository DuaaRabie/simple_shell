#include "main.h"

/**
 * built_cmd - exit the shell
 * @argv: command vector
 * @cmd: command
 * @av: arguments vector
 * @status: pointer to exit status
 * Return: -1 for exit || 0
 */
int built_cmd(char **argv, char **av, char *cmd, int *status)
{
	char *copy = _strdup(cmd);

	if (strtok(copy, " \n") == NULL)
	{
		free_all(argv, cmd, copy);
		return (2);
	}
	free(copy);

	if (_strcmp(argv[0], "exit") == 0)
		exit_fun(argv, cmd, status);
	if (_strcmp(argv[0], "env") == 0)
	{
		free_all(argv, cmd, NULL);
		_env();
		return (1);
	}
	if (_strcmp(argv[0], "unsetenv") == 0)
	{
		_unsetenv(argv[1]);
		free_all(argv, cmd, NULL);
		return (1);
	}
	if (_strcmp(argv[0], "setenv") == 0)
	{
		_setenv(argv[1], argv[2], 1);
		free_all(argv, cmd, NULL);
		return (1);
	}
	if (_strcmp(argv[0], "cd") == 0)
	{
		_cd(argv[1], argv, av);
		free_all(argv, cmd, NULL);
		return (1);
	}

	return (0);
}
