#include "main.h"

/**
 * read_cmd - read the command line from stdin
 *
 * Return: command line
 */
char *read_cmd(void)
{
	char *cmd = NULL;
	size_t cmd_len = 0;
	ssize_t cmd_check;

	if (isatty(STDIN_FILENO))
		write(1, "($) ", 4);
	cmd_check = _getline(&cmd, &cmd_len, stdin);

	if (cmd_check == -1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		free(cmd);
		return (NULL);
	}
	return (cmd);
}
