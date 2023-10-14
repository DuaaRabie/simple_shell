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

	if (fp == stdin)
	{
		while (num_read)
		{
			num_read = read(STDIN_FILENO,
					buffer + total_read, sizeof(buffer) - total_read - 1);
			total_read += num_read;
			if (num_read == (long int)-1)
				return (-1);
			if (num_read == 0)
				return (-1);
			if ((size_t)total_read >= sizeof(buffer) - 1)
				return (-1);
			if (_strchr(buffer, '\n') != NULL)
				break;
		}

		buffer[total_read] = '\0';

		*line = _strdup(buffer);
		if (*line == NULL)
			return (-1);

		*size = total_read;

		return (total_read);
	}

	return (-1);
}
