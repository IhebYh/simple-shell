#include "shell.h"
/**
 * _realloc - entry point
 * @old_size:int
 * @new_size:int
 * @ptr:void
 * Return:void
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *s;
if (new_size == old_size)
return (ptr);
if (new_size == 0 && ptr != NULL)
{
free(ptr);
return (NULL);
}
if (ptr == NULL)
{
ptr = malloc(new_size);
return (ptr);
}
s = malloc(new_size);
free(ptr);
return (s);
}
/**
 * _calloc - entry point
 * @nmemb:int
 * @size:int
 * Return:void
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
unsigned int i;
char *s;
if (nmemb * size == 0)
return (NULL);
s = malloc(nmemb * size);
if (s == NULL)
return (NULL);
for (i = 0; i < nmemb * size; i++)
s[i] = '\0';
return (s);
}
/**
 * free_array - free an array of pointers
 * @a: array of strings
 * Return: void
 */
void free_array(char **a)
{
	int i = 0;

	while (a[i])
		free(a[i++]);
	free(a);
}

