#include "main.h"

/**
 * exec_constructin - check if built in and then exec
 * @d: stat struct input
 * Return: 1 if built in, 0 if not
 */
int exec_constructin(stat *d)
{
	constructin constructin[] = {
		{"exit", constructin_exit},
		{"env", constructin_env},
		{"setenv", constructin_setenv},
		{"unsetenv", constructin_unsetenv},
		{"cd", constructin_cd},
		{NULL, NULL},
	};
	int x = 0;

	for (x = 0; constructin[x].cmd; x++)
	{
		if (_strcmp(d->av[0], constructin[x].cmd) == 0)
		{
			constructin[x].f(d);
			return (1);
		}
	}
	return (0);
}

/**
 * constructin_exit - exits the shell
 * @d: stat struct input
 * Return: 0
 */
void constructin_exit(stat *d)
{
	const char *errorString = "./hsh: 1: exit: Illegal number: ";

	if (d->av[1])
	{
		if (d->av[1][0] != '-' && _isnumber(d->av[1]))
			d->last_exit_status = atoi(d->av[1]);
		else
		{
			write(STDERR_FILENO, errorString, strlen(errorString));
			write(STDERR_FILENO, d->av[1], strlen(d->av[1]));
			write(STDERR_FILENO, "\n", 1);
			d->last_exit_status = 2;
		}
	}
	free_array(d->av);
	free(d->cmd);
	if (d->flag_setenv)
		free_array(environ);
	exit(d->last_exit_status);
}

/**
 * constructin_env - prints the current environment
 * @d: stat struct input
 * Return: 0
 */
void constructin_env(stat *d)
{
	int a = 0;

	(void)d;
	while (environ[a])
	{
		_printf(environ[a]);
		_printf("\n");
		a++;
	}
}
/**
 * constructin_setenv - Initialize a new environment variable,
 * or modify an existing one
 * @d: stat struct input
 * Return: 0
 */

void constructin_setenv(stat *d)
{
	(void)d;
	if (d->av[1] && d->av[2])
	{
		if (_setenv(d, d->av[1], d->av[2]) == -1)
		{
			perror("setenv");
		}
	}
}

/**
 * constructin_unsetenv - Remove an environment variable
 * @d: stat struct input
 * Return: 0
 */
void constructin_unsetenv(stat *d)
{
	int x, j;
	int len;

	(void)d;
	if (!d->av[1] || !getenv(d->av[1]))
	{
		_perror(d->shell_name, "variable not found.");
		return;
	}
	len = strlen(d->av[1]);
	for (x = 0; environ[x]; x++)
		if (strncmp(environ[x], d->av[1], len) == 0 && environ[x][len] == '=')
			for (j = x; environ[j]; j++)
				environ[j] = environ[j + 1];
}
