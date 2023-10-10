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
		if (argv[0][0] == 'e' && argv[0][1] == 'x')
		{
			if (argv[0][2] == 'i' && argv[0][3] == 't')
			{
				free_all(argv, cmd);
				break;
			}
		}
		pid = fork();
		if (pid == -1)
		{
			perror("child doesn't exist");
			return (-1);
		}
		if (pid == 0)
		{
			execve(argv[0], argv, NULL);
			perror("./hsh");
			free_all(argv, cmd);
			break;
		}
		wait(NULL);
		free_all(argv, cmd);
	}
	return (0);
}
