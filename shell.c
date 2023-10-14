#include "main.h"

/**
 * free_all - free argument vector
 * @argv: arguments vector pointer
 * @cmd: command line pointer
 * @cmd_path: the command path
 * Return: nothing
 */
void free_all(char **argv, char *cmd, char *cmd_path)
{
	int i = 0;

	while (argv[i] && argv && argv[0] != cmd_path)
		free(argv[i++]);

	free(argv);
	free(cmd);
	free(cmd_path);
}

/**
 * exe_cmd - fork for executable command
 * @argv: arguments vector
 * @cmd: the command line
 * @cmd_path: the command path
 * Return: nothing
 */
int exe_cmd(char **argv, char *cmd, char *cmd_path)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("child doesn't exist");
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(cmd_path, argv, environ) == -1)
		{
			perror("");
			free_all(argv, cmd, cmd_path);
			return (0);
		}
	}
	wait(NULL);
	return (1);
}

/**
 * main - entry point
 * @ac: count of arguments
 * @av: vector of arguments
 * Return: 0 success | -1 fail
 */
int main(int ac, char **av)
{
	char *cmd = NULL, **argv = NULL, *cmd_path = NULL;
	int exe_return, built_check;

	(void)ac;
	while (1)
	{
		cmd = read_cmd();
		if (cmd == NULL)
			break;
		argv = create_argv(cmd);
		if (argv == NULL)
		{
			free_all(argv, cmd, NULL);
			return (-1);
		}
		built_check = built_cmd(argv, cmd);
		if (built_check == 0)
		{
			cmd_path = get_path(argv);
			if (cmd_path == NULL)
			{
				if ((_strchr(argv[0], '/')) == NULL)
					print_error('c', argv, av);
				else
					print_error('d', argv, av);
				if (isatty(STDIN_FILENO))
					free_all(argv, cmd, cmd_path);
			}
			else
			{
				exe_return = exe_cmd(argv, cmd, cmd_path);
				if (argv[0][0] != 'c' && argv[0][1] != 'l'
						&& argv[0][2] != 'e' && argv[0][3] != 'r')
					free_all(argv, cmd, cmd_path);
				if (exe_return == -1)
					return (exe_return);
				else if (exe_return == 0)
					return (exe_return);
			}
		}
	}

	return (0);
}

