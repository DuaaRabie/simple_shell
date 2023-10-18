#include "main.h"

/**
 * _cd - change directory
 * @dir: directory
 * Return: nothing
 */
void _cd(char *dir)
{
	if (chdir(dir) != 0)
		perror("chdir failed");
}
