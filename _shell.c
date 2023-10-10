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
	size_t cmd_len = 0;
	ssize_t cmd_check;
	pid_t pid;

	while (1)
	{
		cmd = NULL;
		printf("($) ");
		cmd_check = getline(&cmd, &cmd_len, stdin);
		if (cmd_check == -1)
		{
			free(cmd);
			printf("\n");
			break;
		}
		argv = create_argv(cmd);
		if (argv == NULL)
		{
			free_all(argv, cmd);
			return (-1);
		}
		pid = fork();
		if (pid == -1)
		{
			perror("child doesn't exist");
			return (-1);
		}
		if (pid == 0)
		{
			printf("I am the child\n");
			execve(argv[0], argv, NULL);
			free_all(argv, cmd);
			break;
		}
		wait(NULL);
		free_all(argv, cmd);
		printf("I am the parent\n");
	}
	return (0);
}
