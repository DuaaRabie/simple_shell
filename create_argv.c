#include "main.h"

/**
 * check_alloc - check if allocation
 * @ptr: pointer to allocate
 * Return: 0 on success || -1 on fail
 */
int check_alloc(void *ptr)
{
	if (ptr == NULL)
	{
		perror("hsh: memory allocated error");
		return (-1);
	}

	return (0);
}

/**
 * argv_array - create the array
 * @argv: array of the command
 * @cmd: command line
 * @tokens_count: tokens count
 * Return: pointer to argv
 */
char **argv_array(char **argv, char *cmd, size_t tokens_count)
{
	char *cmd_copy = _strdup(cmd);
	char *token = NULL, *delim = " \n";
	int i = 0;

	argv = malloc(sizeof(char *) * tokens_count);
	if (check_alloc(argv) == -1)
	{
		free_all(NULL, cmd, cmd_copy);
		return (NULL);
	}
	_strcpy(cmd_copy, cmd);
	token = strtok(cmd_copy, delim);
	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (check_alloc(argv[i]) == -1)
		{
			free_all(argv, cmd, cmd_copy);
			return (NULL);
		}
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;
	free(cmd_copy);

	return (argv);
}

/**
 * create_argv - create argv
 * @cmd: command line
 * Return: command argv
 */
char **create_argv(char *cmd)
{
	char *token = NULL, *cmd_copy = NULL, **argv = NULL;
	const char *delim = " \n";
	size_t tokens_count = 1;

	cmd_copy = malloc(sizeof(char) * (_strlen(cmd) + 1));
	if (check_alloc(cmd_copy) == -1)
	{
		free(cmd);
		return (NULL);
	}
	_strcpy(cmd_copy, cmd);
	token = strtok(cmd_copy, delim);
	while (token != NULL)
	{
		tokens_count++;
		token = strtok(NULL, delim);
	}
	argv = argv_array(argv, cmd, tokens_count);
	free(cmd_copy);

	return (argv);
}
