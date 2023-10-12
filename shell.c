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
			write(1, argv[0], _strlen(argv[0]));
			perror(" ");
			free_all(argv, cmd, cmd_path);
			return (0);
		}
	}
	wait(NULL);
	if (argv[0][0] != 'c' && argv[0][1] != 'l'
			&& argv[0][2] != 'e' && argv[0][3] != 'r')
	free_all(argv, cmd, cmd_path);
	return (1);
}

/**
 * main - entry point
 *
 * Return: 0 success | -1 fail
 */
int main(void)
{
	char *cmd = NULL, **argv = NULL, *cmd_path = NULL;
	int exe_return, cmd_check;

	while (1)
	{
		cmd = read_cmd();
		if (cmd == NULL)
			break;
		argv = create_argv(cmd);
		if (argv == NULL)
			return (-1);
		cmd_check = built_cmd(argv, cmd);

		if (cmd_check == 0)
		{
			cmd_path = get_path(argv);
			if (cmd_path == NULL)
			{
				write(1, "hsh: ", 5);
				write(1, argv[0], _strlen(argv[0]));
				write(1, ": ", 2);
				perror("");
				free_all(argv, cmd, cmd_path);
			}
			else
			{
				exe_return = exe_cmd(argv, cmd, cmd_path);
				if (exe_return == -1)
					return (exe_return);
				else if (exe_return == 0)
					return (exe_return);
			}
		}
	}
	return (0);
}
