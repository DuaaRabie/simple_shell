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
 * _setenv - set environment variable
 * @var_name: name of the variable
 * @var_value: value of the variable
 * @flag: overwrite flag
 * Return: 0 success | -1 failure
 */
int _setenv(char *var_name, char *var_value, int flag)
{
	char *check = NULL, **env = environ, *temp = NULL;
	int i = 0;

	check = getenv(var_name);
	if (check == NULL)
	{
		while (env[i])
			i++;
		temp = realloc(env[i], sizeof(char) * (_strlen(var_name)
					+ _strlen(var_value) + 2));
		if (temp == NULL)
			return (-1);
		env[i] = temp;
		_strcpy(env[i], var_name);
		_strcat(env[i], "=");
		_strcat(env[i], var_value);
		env[++i] = NULL;
	}
	if (check != NULL && flag != 0)
	{
		while (env[i] && _strncmp(env[i], var_name, _strlen(var_name)) != 0)
			i++;
		if (env[i] == NULL)
		{
			return (-1);
		}
		temp = realloc(env[i], sizeof(char) * (_strlen(var_name) +
					_strlen(var_value) + 2));
		if (temp == NULL)
		{
			perror("can't reallocate memory");
			return (-1);
		}
		env[i] = temp;
		_strcpy(env[i], var_name);
		_strcat(env[i], "=");
		_strcat(env[i], var_value);
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

	check = getenv(var_name);
	if (check != NULL)
	{
		while (env[i] && _strncmp(env[i], var_name, _strlen(var_name)) != 0)
			i++;
		if (env[i] == NULL)
			return (0);
		free(env[i]);
		for (; env[i]; i++)
			env[i] = env[i + 1];
	}

	return (0);
}
