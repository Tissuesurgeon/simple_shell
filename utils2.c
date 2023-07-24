#include "main.h"
/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 *
 * @str: string input
 *
 * Return: a pointer
 */
char *_strdup(const char *str)
{
	int x, len = 0;
	char *resul;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	resul = (char *)malloc((len + 1) * sizeof(char));

	if (resul == NULL)
		return (NULL);

	for (x = 0; x <= len; x++)
		resul[x] = str[x];

	return (resul);
}


/**
 * _isnum - checks if a string is a number
 * @status: string to be checked
 * Return: 0
 */
int _isnum(const char *status)
{
	if (status == NULL || status[0] == '\0')
		return (0);
	while (*status)
	{
		if (!_isdigit(*status))
			return (0);
		status++;
	}
	return (1);
}


/**
 * _isdigit - checks if charachter is number
 * @c: charachter
 * Return: 1 if its a digit 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
