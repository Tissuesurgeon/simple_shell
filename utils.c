#include "main.h"

/**
 * _strlen - return the nbr of char in str
 * @str: string input
 * Return: nbr of char in str.
 */

unsigned int _strlen(char *str)
{
	unsigned int x;

	for (x = 0; str[x] != '\0'; x++)
		;
	return (x);
}


/**
 * _strcmp - compares two strings
 *
 * @s1:  const string
 * @s2:  const string
 *
 * Return: returns an integer indicating the result of the comparison,
 *	as follows:
 *		• 0, if the s1 and s2 are equal
 *		• a negative value if s1 is less than s2
 *		• a positive value if s1 is greater than s2
 */
int _strcmp(const char *s1, const char *s2)
{
	int x;
	int tes = 0;

	for (x = 0; s1[x] != '\0' && s2[x] != '\0'; x++)
	{
		if (s1[x] != s2[x])
		{
			tes = s1[x] - s2[x];
			break;
		}
	}

	return (tes);
}

/**
 * _strncmp - compares two strings.
 *
 * @s1:  const string
 * @s2:  const string
 * @n: input int
 *
 * Return: an integer indicating the result of the comparison,
 *	as follows:
 *		• 0, if the s1 and s2 are equal
 *		• negative value if s1 is less than s2
 *		• positive value if s1 is greater than s2
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i;
	int res = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{

		if (i >= n)
			break;
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}

	return (res);
}

/**
 * _strcpy - copy src to dest .
 *
 * @dest: char *
 * @src: const char *
 *
 * Return: char *
 */
char *_strcpy(char *dest, const char *src)
{
	int len;

	for (len = 0; src[len] != '\0'; ++len)
	{
		dest[len] = src[len];
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * _strcat - adds the src string to the dest string,
 *
 * @dest:  string
 * @src:  const string
 *
 * Return: 0
 */
char *_strcat(char *dest, const char *src)
{
	char *result = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (result);
}
