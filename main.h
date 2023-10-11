#ifndef MAIN_H_
#define MAIN_H_

extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

unsigned int _strlen(char *str);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);

char **create_argv(char *cmd);
void free_all(char **argv, char *cmd, char *cmd_path);
char *read_cmd(void);
int built_cmd(char **argv, char *cmd);
char *get_path(char **argv);
void _env(void);

#endif
