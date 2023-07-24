#include "main.h"

/**
 * _putf - print a string to stander out put
 * @str: string input
 * Return: 0
 */
void _putf(const char *str)
{
	if (!str)
		return;
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}

/**
 * gratis_array - free an array of pointer
 * @array: array of pointer
 * Return: 0
 */
void gratis_array(char **array)
{
	int x;

	if (!array)
		return;

	for (x = 0; array[x]; x++)
	{
		free(array[x]);
		array[x] = NULL;
	}

	free(array);
}

/**
 * divs - split a given string by a delimiter
 * @d: stat struct input
 * @delim: string input
 * Return: 0
 */
void divs(stat *d, const char *delim)
{
	char *chip;
	int nchip = 0;

	d->av = malloc(2 * sizeof(char *));
	if (d->av == NULL)
	{
		free(d->cmd);
		perror(d->shell_name);
		exit(EXIT_FAILURE);
	}
	d->av[0] = NULL;
	d->av[1] = NULL;

	chip = strtok(d->cmd, delim);
	while (chip)
	{
		d->av = realloc(d->av, (nchip + 2) * sizeof(char *));
		if (d->av == NULL)
			goto free;
		d->av[nchip] = _strdup(chip);
		if (d->av[nchip] == NULL)
			goto free;
		nchip++;
		chip = strtok(NULL, delim);
	}
	d->av[nchip] = NULL;
	return;
free:
	free_array(d->av);
	free(d->cmd);
	perror(d->shell_name);
	exit(EXIT_FAILURE);
}

/**
 * pre_data - init data
 * @d: stat struct input
 * @shell_name: string input
 * Return: 0
 */

void pre_data(stat *d, const char *shell_name)
{
	d->cmd = NULL;
	d->av = NULL;
	d->shell_name = shell_name;
	d->last_exit_status = EXIT_SUCCESS;
	d->flag_setenv = 0;
}

/**
 * preuse_cmd - reads the commend from the prompt and structure it into data struct
 * @d: stat struct input
 * Return: 0
 */
void preuse_cmd(stat *d)
{
	size_t n = 0;
	ssize_t nread;
	int i = 0;

	nread = _getline(&d->cmd, &n, stdin);

	if (nread == -1)
	{
		free(d->cmd);
		exit(EXIT_SUCCESS);
	}

	d->cmd[nread - 1] = '\0';
	_trim(d->cmd);
	
	for (i = 0; d->cmd[i] != '\0'; i++)
	{
		if (d->cmd[0] == '#' || (d->cmd[i] == '#' && d->cmd[i - 1] == ' '))
		{
			d->cmd[i] = '\0';
			break;
		}
	}
	_trim(d->cmd);
}
