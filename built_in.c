#include "shell.h"

/**
* b_exit - Exit shell 
* @cmd: Parsed command
* @input: User Input
* @argv: program name
* @c: Execute count
* Return : void
*/
int b_exit(char **cmd)
{
    int status, i = 0;
    if (cmd[1] == NULL)
    {
        free(cmd);
        exit(EXIT_SUCCESS);
    }
    while(cmd[1][i])
    {
        if(_isalpha(cmd[1][i++]) != 0)
        {
            /* print error */
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