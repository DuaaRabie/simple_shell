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
 * @argv: command vector
 * @cmd: the command line
 * @cmd_path: the command path
 * @av: arguments vector
 * @status: pointer to exit status
 * Return: nothing
 */
int exe_cmd(char **argv, char *cmd, char *cmd_path, char **av, int *status)
{
	char **env = environ;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("child doesn't exist");
		free_all(argv, cmd, cmd_path);
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(cmd_path, argv, env) == -1)
		{
			print_error('d', argv, av);
			free_all(argv, cmd, cmd_path);
			return (0);
		}
	}
	waitpid(pid, status, 0);
	return (1);
}

/**
 * error_msg - error message
 * @av: argument vector
 * @argv: command argument vector
 * Retrun: nothing
 */
void error_msg(char **av, char **argv)
{

	if ((_strchr(argv[0], '/')) == NULL)
		print_error('c', argv, av);
	else
		print_error('d', argv, av);
}

/**
 * check_path - check if path available and it accessible
 * @argv: command vector
 * @av: arguments vector
 * @cmd: command line
 * @status: pointer to exit status
 * Return: 0 | 1 | -1
 */
int check_path(char **av, char **argv, char *cmd, int *status)
{
	char *cmd_path = NULL;
	int exe_return;


	cmd_path = get_path(argv);
	if (cmd_path == NULL)
	{
		error_msg(av, argv);
		exit(127);
	}
	else
	{
		if (access(cmd_path, X_OK) != 0)
		{
			print_error('d', argv, av);
			*status = 127;
		}
		else
		{
			exe_return = exe_cmd(argv, cmd, cmd_path, av, status);
			if (exe_return == -1 || exe_return == 0)
				return (exe_return);
		}
	}
	free_all(argv, cmd, cmd_path);
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
	char *cmd = NULL, **argv = NULL;
	int path_check, built_check, status = 0;

	(void)ac;
	while (1)
	{
		cmd = read_cmd();
		if (cmd == NULL)
			exit(status);
		if (!(cmd[0] == '\n' && isatty(STDIN_FILENO)))
		{
			argv = create_argv(cmd);
			if (argv == NULL)
				exit(127);
			built_check = built_cmd(argv, av, cmd, &status);
			if (built_check == 0)
			{
				path_check = check_path(av, argv, cmd, &status);
				if (path_check == 0 || path_check == -1)
					exit(127);
			}
		}
		else
			free(cmd);
	}
	return (0);
}

