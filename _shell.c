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
 * fork_process - fork for executable files
 * @argv: arguments vector
 * @cmd: the command line
 * @cmd_path: the command path
 * Return: nothing
 */
int fork_process(char **argv, char *cmd, char *cmd_path)
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
			free_all(argv, cmd, cmd_path);
			perror("./hsh");
			return (0);
		}
	}
	wait(NULL);
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
	int fork_return;

	while (1)
	{
		cmd = read_cmd();
		if (cmd == NULL)
			break;
		argv = create_argv(cmd);
		if (argv == NULL)
			return (-1);
		if (exit_check(argv, cmd) == -1)
			break;
		cmd_path = get_path(argv);
		if (cmd_path == NULL)
		{
			free_all(argv, cmd, cmd_path);
			perror("./hsh");
		}
		else
		{
			fork_return = fork_process(argv, cmd, cmd_path);
			if (fork_return == -1)
				return (-1);
			else if (fork_return == 0)
				break;
		}
	}
	return (0);
}
