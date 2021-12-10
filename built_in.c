#include "shell.h"

/**
* b_exit - Exit shell
* @cmd: Parsed command
* Return: int
*/
int b_exit(char **cmd)
{
	int status, i = 0;

	if (cmd[1] == NULL)
	{
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) != 0)
		{
			/* print error */
			free(cmd);
			break;
		}
		else
		{
			status = _atoi(cmd[1]);
			free(cmd);
			exit(status);
		}
	}
	return (0);
}
/**
* b_env - print env
* @_argv: char**
* Return:int
**/
int b_env(char **_argv __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		if (write(STDOUT_FILENO, environ[i], _strlen(environ[i])) == -1)
		{
			perror("env");
			return (-1);
		}
		write(STDOUT_FILENO, "\n", 1);

		i++;
	}
	return (1);
}
