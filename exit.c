#include "main.h"

/**
 * exit_fun - exit the shell
 * @argv: arguments vector
 * @cmd: command
 * Return: nothing
 */
void exit_fun(char **argv, char *cmd)
{
	int exit_value = 0, i = 0;
	char *not_num = ": numeric argument required\n";
	char *not_num2 = "Illegal number";

	while (argv[1])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
		{
			exit_value = (exit_value * 10) + (argv[1][i] - 48);
			i++;
		}
		else
		{
			if (argv[1][i] == '\n' || argv[1][i] == '\0')
				break;
			write(1, "./hsh: exit: ", 13);
			if (isatty(STDIN_FILENO))
			{
				write(1, argv[1], _strlen(argv[1]));
				write(1, not_num, _strlen(not_num));
			}
			else
			{
				write(1, not_num2, _strlen(not_num2));
				write(1, ": ", 2);
				write(1, argv[1], _strlen(argv[1]));
				write(1, "\n", 1);
			}
			exit_value = 2;
			break;
		}
	}
	free_all(argv, cmd, NULL);
	exit(exit_value);
}
