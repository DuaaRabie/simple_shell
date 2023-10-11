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
 * create_argv - create argv
 * @cmd: command line
 * Return: command argv
 */
char **create_argv(char *cmd)
{
	char *token = NULL, *cmd_copy = NULL;
	char **argv;
	const char *delim = " \n";
	size_t tokens_count = 1;
	int i = 0;

	cmd_copy = malloc(sizeof(char) * _strlen(cmd));
	if (check_alloc(cmd_copy) == -1)
		return (NULL);
	_strcpy(cmd_copy, cmd);

	token = strtok(cmd, delim);
	while (token != NULL)
	{
		tokens_count++;
		token = strtok(NULL, delim);
	}

	argv = malloc(sizeof(char *) * tokens_count);
	if (check_alloc(argv) == -1)
		return (NULL);

	token = strtok(cmd_copy, delim);
	while (token != NULL)
	{
		argv[i] = malloc(sizeof(char) * _strlen(token));
		if (check_alloc(argv[i]) == -1)
			return (NULL);
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	argv[i] = NULL;

	free(cmd_copy);

	if (argv == NULL)
		free_all(argv, cmd, NULL);

	return (argv);
}
