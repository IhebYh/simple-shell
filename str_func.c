#include "shell.h"
/**
 * _strcmp - entry point
 * @s1:char
 * @s2:char
 * Return:char
 */
int _strcmp(char *s1, char *s2)
{
while ((*s1 != '\0') && (*s2 != '\0'))
{
if (*s1 == *s2)
{
s1++;
s2++;
continue;
}
else if (*s1 != *s2)
return (*s1 - *s2);
}
return (0);
}
/**
 * _strdup - entry point
 * @str:char
 * Return:Null or pointer
 */
char *_strdup(char *str)
{
int i = 0, j = 0;
char *s;
if (str == NULL)
return (NULL);
for (; str[i]; i++)
j++;
s = malloc((j + 1) * sizeof(char));
if (s == 0)
return (NULL);
for (i = 0; i < j ; i++)
s[i] = str[i];
s[j] = '\0';
return (s);
}
/**
 * _strcat - entry point
 * @dest:char
 * @src:char
 * Return:char
 */

char *_strcat(char *dest, char *src)
{
char *s = dest;
while (*dest != '\0')
{
dest++;
}
while (*src != '\0')
{
*dest = *src;
dest++;
src++;
}
*dest = '\0';
return (s);
}
/**
 * _strlen - entry point
 * @s :char
 * Return:int
 */
int _strlen(char *s)
{
int i;
for (i = 0; s[i] != '\0'; i++)
{
continue;
}
return (i);
}
/**
 * _strncmp - Compare Amount (n) Of Characters Of Two Strings.
 * @s1: A String.
 * @s2: A String.
 * @n: Amount Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}