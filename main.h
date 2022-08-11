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

void run_prompt(void);

int exec_cmd(char **args);
void run_env_checker(char *prompt_text);
int run_check_cmd_exists(char **cmd);
void run_exit_checker(char *prompt_text);
void runner(char **cmd);

char *read_prompt(void);
char **tokenize(char *line);
char **check_realloc(int position, int bufsize, char **tokens);
void check_alloc_error(char **token);

int _putchar(char c);
char *_strcat(char *dest, char *src);
void _stream_writer(char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
#endif