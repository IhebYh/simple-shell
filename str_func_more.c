#include "shell.h"
/**
 * _strcpy - entry point
 * @dest:char
 * @src:char
 * Return:char *
 */
char *_strcpy(char *dest, char *src)
{
int i;

i = 0;
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
}
/**
 * _atoi - entry point
 * @s:string
 * Return:int
 */

int _atoi(char *s)
{
int i = 0, j, n = 0, y = 1;

while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
{
if (s[i] == '-')
y *= -1;
i++;
}
j = i;
while ((s[j] >= '0') && (s[j] <= '9'))
{
n = (n * 10) + y * ((s[j]) - '0');
j++;
}
return (n);
}
/**
 * _isalpha - Entry point
 *
 * @c : Char
 *
 * Return: Always 1 (Success)
 */
int _isalpha(int c)
{
if (((c >= 97) && (c <= 122)) || ((c >= 65) && (c <= 92)))
return (1);
return (0);
}

