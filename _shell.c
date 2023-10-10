#include "main.h"

/**
 * free_all - free argument vector
 * @argv: arguments vector pointer
 * @cmd: command line pointer
 * Return: nothing
 */
void free_all(char **argv, char *cmd)
{
	int i = 0;

	while (argv[i] && argv)
		free(argv[i++]);

	free(argv);
	free(cmd);
}

/**
 * main - entry point
 *
 * Return: 0 success | -1 fail
 */
int main(void)
{
	char *cmd = NULL, **argv = NULL;
	pid_t pid;

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

		pid = fork();
		if (pid == -1)
		{
			perror("child doesn't exist");
			return (-1);
		}
		if (pid == 0)
		{
			execve(argv[0], argv, environ);
			perror("./hsh");
			free_all(argv, cmd);
			break;
		}
		wait(NULL);
		free_all(argv, cmd);
	}
	return (0);
}
