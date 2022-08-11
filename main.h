#ifndef _MAIN_H_
#define _MAIN_H_
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>

extern char **environ;

void prompt(void);
char *run_cmd(char *command);

int _strcmpdir(char *s1, char *s2);
int _putchar(char c);
char *_strcat(char *dest, char *src);
int find_trailing_slash(char *cmd);
int _strlen(char *s);
void _stream_writer(char *str);
int _strcmp(char *s1, char *s2);

void run_shell(int sig);
void exec_cmd(char **cmd);
char **call_params(char *parameter);
#endif