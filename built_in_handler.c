#include "shell.h"

/**
* builtin_checker - check built in
* @cmd: command to check
* Return: 0 in case of success else -1
*/
int builtin_checker(char **cmnd)
{
bul_t bul[] = {
{"exit", NULL},
{"env", NULL},
{NULL, NULL}
};
int i = 0;
if (*cmnd == NULL)
return (-1);
while ((bul + i)->cmd)
{
if (_strcmp(cmnd[0], (bul + i)->cmd))
return (0);
i++;
}
return (-1);
}
/**
 * builtin_handler - Handle Builtin Command
 * @cmnd: Parsed Command
 * Return: 1(Fail) or 0(Success)
  */
int builtin_handler(char **cmnd)
{
bul_t bul[] = {
{"exit", b_exit},
{"env", b_env},
{NULL, NULL}
};
int i = 0;
while ((bul + i)->cmd)
{
if (_strcmp(cmnd[0], (bul + i)->cmd) == 0)
{
return ((bul + i)->fun(cmnd));
}
i++;
}
return (-1);
}
/**
 * signal_to_handel - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void signal_to_handel(int sig)
{
	if (sig == SIGINT)
	{
		write(STDOUT_FILENO, "\n$ ", 2);
	}
}