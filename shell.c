#include "shell.h"
/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: Exit Value By Status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int counter = 0, statue = 1, st = 0;

	signal(SIGINT, signal_to_handel);
	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			b_exit(cmd);
		}
		else if (builtin_checker(cmd) == 0)
		{
			st = builtin_handler(cmd);
			free_all(cmd, input);
			continue;
		}
		else
		{
			st = cmd_checker(cmd);

		}
		free_all(cmd, input);
	}
	return (statue);
}