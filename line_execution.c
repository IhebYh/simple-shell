#include "shell.h"

/**
* _execve - execute a line of commands
* @_argv: line of commands
* Return: void
*/
void _execve(char **_argv)
{
	pid_t _p1, _p2;
	int status;

	_p1 = fork();
	if (_p1 == -1)
	/* print error */
	if (_p1 == 0)
	{
		_p2 == execve(_argv[0], _argv, environ);
		if (_p2 == -1)
		{
			/* print error */
			free_array(_argv);
			exit(1);
		}
	}
	else
	wait(&status);
}
/**
* cmd_checker - check the line of command given by the user
* @cmd: char
* Return: void
*/
void cmd_checker(char *cmd)
{
	char **_argv;

	cmd[_strlen(cmd) + 1] = '\0';
	_argv = _strtok(cmd, " ");
	if (_argv != NULL)
	{
		if (builtin_checker(_argv) == 0)
		{
			builtin_handler(_argv);
		}
		else if (path_handler(&_argv[0]))
		{
			_execve(_argv);
			free_array(_argv);
		}
		else
		{
		/* TODO : PRINT ERROR */
		free_array(_argv);
		}
	}
}
