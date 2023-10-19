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
		write(2, av[0], _strlen(av[0]));
		write(2, ": ", 2);
		write(2, argv[0], _strlen(argv[0]));
		switch (ch)
		{
			case 'c':
				write(2, c, _strlen(c));
				break;
			case 'd':
				write(2, d, _strlen(d));
				break;
		}
	}
	else
	{
		 write(2, av[0], _strlen(av[0]));
		 write(2, ": 1: ", 5);
		 write(2, argv[0], _strlen(argv[0]));
		 write(2, ": not found\n", 12);
	}
}
