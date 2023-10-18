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
char *_strchr(char *s, char c);
int _strncmp(char *s1, char *s2, int n);

char **create_argv(char *cmd);
void free_all(char **argv, char *cmd, char *cmd_path);
char *read_cmd(void);
int built_cmd(char **argv, char *cmd);
char *get_path(char **argv);
void _env(void);
void print_error(char ch, char **argv, char **av);
void exit_fun(char **argv, char *cmd);
int _setenv(char *var_name, char *var_value, int flag);
int _unsetenv(char *var_name);

int _getline(char **line, size_t *size, FILE *fp);

#endif
