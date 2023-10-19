#include "main.h"

/**
 * print_error - prints error msgs
 * @ch: cmd type
 * @argv: array of the cmd
 * @av: arguments vector
 * Return: nothing
 */
void print_error(char ch, char **argv, char **av)
{
	char c[] = ": command not found\n";
	char d[] = ": No such file or directory\n";

	if (isatty(STDIN_FILENO))
	{
		write(1, av[0], _strlen(av[0]));
		write(1, ": ", 2);
		write(1, argv[0], _strlen(argv[0]));
		switch (ch)
		{
			case 'c':
				write(1, c, _strlen(c));
				break;
			case 'd':
				write(1, d, _strlen(d));
				break;
		}
	}
	else
	{
		 write(1, av[0], _strlen(av[0]));
		 write(1, ": 1: ", 5);
		 write(1, argv[0], _strlen(argv[0]));
		 write(1, ": not found\n", 12);
	}
}
