#include "main.h"
/**
 * reset - set to 0
 * @value1: pointer to value to be reset
 * @value2: pointer value to be reset
 * Return: nothing
 */
void reset(int *value1, int *value2)
{
	*value1 = 0;
	*value2 = 0;
}

/**
 * check_line - check read line
 * @line: pointer of line address
 * @size: the size pointer
 * @buffer: buffer contains all lines
 * @ptr: pointer to check line
 * @round: pointer to round
 */
void check_line(char **line, size_t *size, char *buffer, char *ptr, int *round)
{
	static int newlines;
	int i = 0, check_line = 0;

	if (newlines == 0)
	{
		ptr = strdup(buffer);
		while (*ptr)
		{
			if (*ptr == '\n')
				newlines++;
			ptr++;
		}
	}
	if (newlines > 1 && *round < newlines)
	{
		ptr = _strdup(buffer);
		for (i = 0; ptr[i] != '\0'; i++)
		{
			if (ptr[i] == '\n')
			{
				if (++check_line == *round + 1)
				{
					*round = *round + 1;
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
	if (*round == newlines)
		reset(round, &newlines);
}

/**
 * _getline - custome getline function
 * @line: pointer to store the line in
 * @size: pointer to the size of the line
 * @fp: file pointer to read from
 * Return: number of read characters | -1 fail
 */
int _getline(char **line, size_t *size, FILE *fp)
{
	char *ptr = NULL;
	static char buffer[1024] = {0};
	ssize_t num_read = 1, total_read = 0;
	static int round;

	if (fp == stdin && round == 0)
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
			if (_strchr(buffer, '\n') != NULL)
				break;
		}
		buffer[total_read] = '\0';
		*size = total_read;
		*line = _strdup(buffer);
		if (*line == NULL)
			return (-1);
	}
	check_line(line, size, buffer, ptr, &round);
	return (_strlen(*line));
}
