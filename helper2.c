#include "main.h"

/**
 * _pflaw - print in stderr
 * @str1: shell program
 * @str2: message error
 * Return: 0
 */
void _pflaw(const char *str1, const char *str2)
{
    if (!str1 || !str2)
        return;

    while (*str1)
    {
        write(STDERR_FILENO, str1, 1);
        str1++;
    }

    write(STDERR_FILENO, ": ", 2);

    while (*str2)
    {
        write(STDERR_FILENO, str2, 1);
        str2++;
    }
    write(STDERR_FILENO, "\n", 1);
}


/**
 * _remove - remove leading and trailing spaces and tabs from a string
 * @str: string input
 * Return: 0.
 */

void _remove(char *str)
{
    int x, j, len = _strlen(str);

    for (x = 0; x < len && (str[x] == ' ' || str[x] == '\t'); x++)
        ;

    for (j = 0; x < len ; x++, j++)
        str[j] = str[x];

    str[j] = '\0';

    for (x = _strlen(str) - 1; x > 0 && (str[x] == ' ' || str[x] == '\t'); x--)
        str[x] = '\0';
}


/**
 * _respace - reallocates a memory block 
 *
 * @ptr: pointer void
 * @new_size: unsigned int
 *
 * Return: newly allocated memory
 */
void *_respace(void *ptr, unsigned int new_size)
{
    char *r;
    unsigned int x, tp = new_size, old_size = sizeof(ptr);

    if (old_size == new_size)
        return (ptr);
    if (ptr == NULL)
        return (malloc(new_size));

    if (new_size > old_size)
        tp = old_size;

    if (new_size == 0)
    {
        free(ptr);
        return (NULL);
    }

    r = malloc(new_size);

    for (x = 0; x < tp; x++)
        r[x] = ((char *)ptr)[x];
    free(ptr);
    return (r);
}
