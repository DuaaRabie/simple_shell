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
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_memcpy(char *dest, char *src, unsigned int n);

char **create_argv(char *cmd);
void free_all(char **argv, char *cmd, char *cmd_path);
char *read_cmd(void);
int built_cmd(char **argv, char **av, char *cmd, int *status);
char *get_path(char **argv);
void _env(void);
void print_error(char ch, char **argv, char **av);
void exit_fun(char **argv, char *cmd, int *status);
int _setenv(char *var_name, char *var_value, int flag);
int _unsetenv(char *var_name);
void _cd(char *dir, char **argv, char **av);
int _getline(char **line, size_t *size, FILE *fp);

#endif
