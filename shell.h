#ifndef SHELL_H
#define SHELL_H

/* ######### LIBRARIES #########*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>
#include <sys/stat.h>


/* ######### MACROS ######## */

#define INFINITE_LOOP 1

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
char **_strtok(const char *str, const char del);

/* MEMORY MANAGEMENT */

void free_array(char **a);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void *_calloc(unsigned int nmemb, unsigned int size);

/* PATH HANDLER FUNCTIONS */

char *path_maker(char *p, char *f);
char *path_handler(char **str);

/* EXECVE FUNCTIONS */

void cmd_checker(char *cmd);
void _execve(char **_argv);

/* GETENV FUNCTION */

char *_getenv(const char *name);

/* BUILT IN FUNCTIONS */

int builtin_handler(char **cmd);
int builtin_checker(char **cmd);
int b_exit(char **cmd);

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
