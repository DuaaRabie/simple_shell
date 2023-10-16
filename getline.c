#include "main.h"

/**
 * _getline - custome getline function
 * @line: pointer to store the line in
 * @size: pointer to the size of the line
 * @fp: file pointer to read from
 * Return: number of read characters | -1 fail
 */
int _getline(char **line, size_t *size, FILE *fp)
{
	static char buffer[1024] = {0};
	ssize_t num_read = 1, total_read = 0;
	char *ptr;
	static int newlines = 0, repeat = 0;
	int i = 0, check_line = 0;

	if (fp == stdin && repeat == 0)
	{
		while (num_read)
		{
			num_read = read(STDIN_FILENO,
					buffer + total_read, sizeof(buffer) - total_read - 1);
			total_read += num_read;
			if (num_read == (long int)-1)
				return (-1);
			if (num_read == 0 && total_read == 0)
				return (-1);
			if (num_read == 0 && total_read != 0)
				break;
			if ((size_t)total_read >= sizeof(buffer) - 1)
				return (-1);
			ptr = _strchr(buffer, '\n');
			if (ptr != NULL)
			{
				break;
			}
		}

		buffer[total_read] = '\0';

		*size = total_read;
		*line = _strdup(buffer);
		if (*line == NULL)
			return (-1);
	}

	if (newlines == 0)
	{
		while (*ptr)
		{
			if (*ptr == '\n')
				newlines++;
			ptr++;
		}
	}

	if (newlines > 1 && repeat < newlines)
	{
		ptr = _strdup(buffer);
		for (i = 0; ptr[i] != '\0'; i++)
		{
			if (ptr[i] == '\n')
			{
				check_line++;
				if (check_line == repeat + 1)
				{
					repeat++;
					ptr[++i] = '\0';
					*size = _strlen(ptr);
					*line = _strdup(ptr);
					break;
				}
				else
				{
					ptr = &ptr[++i];
					i = 0;
				}
			}
		}
	}
	if (repeat == newlines)
	{
		repeat = 0;
		newlines = 0;
	}

	return (total_read);
}
