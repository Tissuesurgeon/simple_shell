#include "main.h"

/**
 * init_process - start a new process
 * @d: stat struct input
 * Return: 0
 */

void init_process(stat *d)
{
    pid_t sub_pid = fork();
    int status = 0;

    if (sub_pid == -1)
        goto free;
    if (sub_pid == 0 && execve(d->av[0], d->av, NULL) == -1)
        goto free;
    else if (wait(&status) == -1)
        goto free;
    if (WIFEXITED(status))
        d->last_exit_status = WEXITSTATUS(status);
    return;
free:
    perror(d->shell_name);
    free_array(d->av);
    free(d->cmd);
    exit(EXIT_FAILURE);
}

/**
 * sig_handl - Signal handler function
 * @signal: int input
 * Return: 0
 */

void sig_handl(int signal)
{
    /*const char prompt[] = PROMPT;*/
    (void)signal;
    exit(EXIT_FAILURE);
    /*_printf(prompt);*/
}

/**
 * _xec - exectute cmd
 * @d: data struct input
 * Return: 0
 */

void _xec(stat *d)
{
    const char prompt[] = PROMPT;

    signal(SIGINT, sig_handl);

    while (1)
    {
        if (isatty(STDIN_FILENO))
            _putf(prompt);

        read_cmd(d);
        if (_strlen(d->cmd) != 0)
        {
            split(d, " ");
            if (!exec_constructin(d))
            {
                _which(d);
                if (access(d->av[0], F_OK) == -1)
                {
                    perror(d->shell_name);
                }
                else
                {
                    init_process(d);
                }
            }
            gratis_array(d->av);
        }
        free(d->cmd);
    }
}
