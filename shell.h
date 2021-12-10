#ifndef SHELL_H
#define SHELL_H

/* ######### LIBRARIES #########*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/* ######### MACROS ######## */

#define INFINITE_LOOP 1
#define BUFSIZE 1024

/* ######## ENVIRON DECLARATION ###### */

extern char **environ;

/* ##########"FUNCTIONS ########### */

/* STR FUNCTIONS*/

int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _isalpha(int c);
int _atoi(char *s);
char *_strtok(char *str, const char *delim);
unsigned int check_delim(char c, const char *str);
int _strncmp(const char *s1, const char *s2, size_t n);

/* MEMORY MANAGEMENT */

void free_array(char **a);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void free_all(char **cmd, char *line);
char *_memcpy(char *dest, char *src, unsigned int n);
void *fill_an_array(void *a, int el, unsigned int len);

/* PATH HANDLER FUNCTIONS */

char *build(char *token, char *value);
int path_cmd(char **cmd);
void signal_to_handel(int sig);

/* EXECVE FUNCTIONS */

int cmd_checker(char **cmd);

/* PARSSING FUNCTION */

char **parse_cmd(char *input);

/* GETENV FUNCTION */

char *_getenv(const char *name);

/* BUILT IN FUNCTIONS */

int builtin_handler(char **cmd);
int builtin_checker(char **cmnd);
int b_exit(char **cmd);
int b_env(char **_argv);

/* GETLINE */ 

char *_getline();
void hashtag_handle(char *buff);

/* BUILT IN STRUCT */

/**
 * struct bulltin - contain bultin to handle and function to excute
 * @cmd:pointer to char
 * @fun:fun to excute when bultin true
 */

typedef struct  bulltin
{
	char *cmd;
	int (*fun)(char **line);
} bul_t;

#endif
