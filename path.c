#include "main.h"

/**
 * get_path - get path and check it
 * @argv: arguments vector
 * Return: path
 */
char *get_path(char **argv)
{
	char *cmd_path = NULL, *path_token = NULL;
	char *all_paths = NULL, *paths_copy = NULL;
	struct stat statbuf;

	if (stat(argv[0], &statbuf) == 0)
	{
		if (getenv("PATH") == NULL)
			return (NULL);
		cmd_path = _strdup(argv[0]);
		return (cmd_path);
	}
	if ((argv[0][0] == '.' && argv[0][1] ==  '/') || (argv[0][0] == '/'))
	{
		cmd_path = _strdup(argv[0]);
		return (cmd_path);
	}
	all_paths = getenv("PATH");
	if (all_paths == NULL)
		return (NULL);
	paths_copy = _strdup(all_paths);
	path_token = strtok(paths_copy, ":");
	while (path_token)
	{
		cmd_path = malloc(sizeof(char) * (_strlen(argv[0]) +
					_strlen(path_token) + 2));
		_strcpy(cmd_path, path_token);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, argv[0]);
		_strcat(cmd_path, "\0");
		if (stat(cmd_path, &statbuf) == 0)
		{
			free(paths_copy);
			return (cmd_path);
		}
		free(cmd_path);
		path_token = strtok(NULL, ":");
	}
	free(paths_copy);
	return (NULL);
}
