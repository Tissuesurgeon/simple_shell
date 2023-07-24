#define PROMPT "#csisfun$ "

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/wait.h>
#include <errno.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/**
 * struct stat - holds the main data.
 * @av: Array of tokens to pass for execve
 * @cmd: The user input, the command line
 * @shell_name: The name of the shell program
 * @last_exit_status: last exit status of last command executed
 * @flag_setenv: 1 if user did exec setenv (use it to free memory)
 */
typedef struct stat
{
	char **av;
	char *cmd;
	const char *shell_name;
	int last_exit_status;
	int flag_setenv;
} stat;

/**
 * struct constructin - holds the main data.
 * @cmd: built in cmd
 * @f: function of constructin cmd
 */
typedef struct constructin
{
	const char *cmd;
	void (*f)(stat *d);
} constructin;

/* constructin.c */
int exec_constructin(stat *d);
void constructin_exit(stat *d);
void constructin_env(stat *d);
void constructin_setenv(stat *d);
void constructin_unsetenv(stat *d);
void constructin_cd(stat *d);


/* helpers.c */
void _putf(const char *str);
void gratis_array(char **array);
void divs(stat *d, const char *delim);
void pre_data(stat *d, const char *shell_name);
void preuse_cmd(stat *d);


/* helpers2.c */
void _pflaw(const char *str1, const char *str2);
void _remove(char *str);
void *_respace(void *ptr, unsigned int new_size);


/* exec.c */
void init_process(stat *d);
void sig_handl(int sig);
void _xec(stat *d);


/* way.c */
char *_getenv(char *name);
int _what(stat *d);
int _asignenv(stat *d, char *name, char *value);


/* utils.c */
unsigned int _strlen(char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, int n);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);

/* utils2.c */
char *_strdup(const char *str);
int _isnum(const char *status);
int _isdigit(int c);

/* line.c */
#define READ_BUF_SIZE 1024

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);


#endif
