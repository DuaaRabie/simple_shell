#include "main.h"

/**
 * _env - prints current environment
 *
 * Return: nothing
 */
void _env(void)
{
	char **env = environ;

	for (; *env != NULL; ++env)
	{
		printf("%s\n", *env);
	}
}

/**
 * copy_var - copy name and value
 * @i: location of var in the array
 * @var_name: variable name
 * @var_value: variable value
 * @env: environment variable
 * Return: nothing
 */
int copy_var(char *var_name, char *var_value, int i)
{
	int new_len = _strlen(var_name) + _strlen(var_value) + 2;
	char *temp = NULL;

	temp = malloc(sizeof(char) * new_len);
	if (temp == NULL)
	{
		perror("allocation faild");
		return (-1);
	}
	_strcpy(temp, var_name);
	_strcat(temp, "=");
	_strcat(temp, var_value);
	environ[i] = _strdup(temp);
	free(temp);
	return (0);
}

/**
 * _setenv - set environment variable
 * @var_name: name of the variable
 * @var_value: value of the variable
 * @flag: overwrite flag
 * Return: 0 success | -1 failure
 */
int _setenv(char *var_name, char *var_value, int flag)
{
	char *check = NULL, **env = environ;
	int i = 0;

	if (var_name == NULL || var_value == NULL)
	{
		perror("few arguments");
		return (-1);
	}
	check = getenv(var_name);
	if (check == NULL)
	{
		while (env[i])
			i++;
		if (copy_var(var_name, var_value, i) == -1)
			return (-1);
		env[++i] = NULL;
	}
	if (check != NULL && flag != 0)
	{
		while (env[i] && _strncmp(env[i], var_name, _strlen(var_name)) != 0)
			i++;
		if (env[i] == NULL)
		{
			perror("variable not found");
			return (-1);
		}
		free(environ[i]);
		if (copy_var(var_name, var_value, i) == -1)
			return (-1);
	}
	return (0);
}

/**
 * _unsetenv - unset environment variable
 * @var_name: variable to be unset
 * Return: 0 success | -1 failure
 */
int _unsetenv(char *var_name)
{
	char **env = environ, *check = NULL;
	int i = 0;

	if (var_name == NULL)
	{
		perror("few arguments");
		return (-1);
	}
	check = getenv(var_name);
	if (check != NULL)
	{
		while (env[i] && _strncmp(env[i], var_name, _strlen(var_name)) != 0)
			i++;
		if (env[i] == NULL)
			return (-1);
		free(environ[i]);
		for (; environ[i]; i++)
			environ[i] = environ[i + 1];
	}

	return (0);
}
