#include "shell.h"

/**
* builtin_checker - check built in
* @cmd: command to check
* Return: 0 in case of success else -1
*/
int builtin_checker(char **cmd)
{
bul_t bul[] = {
{"exit", NULL},
{"env", NULL},
{NULL, NULL}
};
int i = 0;
if (*cmd == NULL)
return (-1);
while ((bul + i)->cmd)
{
if (_strcmp(cmd[0], (bul + i)->cmd))
return (0);
i++;
}
return (-1);
}
/**
 * builtin_handler - Handle Builtin Command
 * @cmd: Parsed Command
 * Return: 1(Fail) or 0(Success)
  */
int builtin_handler(char **cmd)
{
bul_t bul[] = {
{"exit", _exit},
{"env", _env},
{NULL, NULL}
};
int i = 0;
while ((bul + i)->cmd)
{
if (_strcmp(cmd[0], (bil + i)->cmd) == 0)
{
return ((bil + i)->fun(cmd));
}
i++;
}
return (-1);
}
