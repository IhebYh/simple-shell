#include "shell.h"
/**
* path_handler - handling the path
* @str:string
* Return: char
*/
char *path_handler(char **str)
{
	int i = 0;
	char **path_array, *p, *path;
	struct stat st;

	path = _getenv("PATH");
	if (_strlen(path) == 0)
	return (NULL);
	path_array = _strtok(path, ':');
	if (!path_array)
	return (NULL);

	while (path_array[i] != NULL)
	{
		p = path_maker(path_array[i], *str);
		if (stat(p, &st) == 0)
		{
			free(*str);
			*str = p;
			free_array(path_array);
			return (p);
		}
		free(p);
		i++;
	}
	free_array(path_array);
	return (NULL);
}
/**
* path_maker - Making a path from the value gotten from the getenv function
* @p:char*
* @f:char*
* Return:char
*/
char *path_maker(char *p, char *f)
{
	char *str;

	if (p == NULL || f == NULL)
	return (NULL);

	str = malloc(_strlen(p) + _strlen(f) + 2);
	if (str == NULL)
	return (NULL);
	_strcpy(str, p);
	str[_strlen(p)] = '/';
	str[_strlen(p) + 1] = '\0';
	_strcat(str, f);
	str[_strlen(p) + _strlen(f) + 2] = '\0';
	return (str);
}
