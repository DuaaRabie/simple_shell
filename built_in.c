#include "main.h"

/**
 * built_cmd - exit the shell
 * @argv: arguments vector
 * @cmd: command
 * Return: -1 for exit || 0
 */
int built_cmd(char **argv, char *cmd)
{
	int exit_value = 0, i = 0;
	static int j = 1;
	char *not_num = ": exit: Illegal number: ", c[1];

	if (argv[0][0] == 'e' && argv[0][1] == 'x'
			&& argv[0][2] == 'i' && argv[0][3] == 't')
	{
		while (argv[1])
		{
			if (argv[1][i] >= '0' && argv[1][i] <= '9')
			{
				exit_value = (exit_value * 10) + (argv[1][i] - 48);
				i++;
			}
			else if (argv[1][i] == '\n' || argv[1][i] == '\0')
				break;
			else
			{
				c[0] = j++ + 48;
				c[1] = '\0';
				write(1, "./hsh: ", 7);
				write(1, c, 1);
				write(1, not_num, _strlen(not_num));
				write(1, argv[1], _strlen(argv[1]));
				write(1, "\n", 1);
				exit_value = i;
				return (2);
			}
		}
		free_all(argv, cmd, NULL);
		exit(exit_value);
	}

	if (argv[0][0] == 'e' && argv[0][1] == 'n' && argv[0][2] == 'v')
	{
		free_all(argv, cmd, NULL);
		_env();
		return (1);
	}

	return (0);
}
