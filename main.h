#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

unsigned int _strlen(char *str);
char **create_argv(char *cmd);

#endif
