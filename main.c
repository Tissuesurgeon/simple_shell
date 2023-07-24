#include "main.h"

/**
 * main -  data
 * @argc: size of @argv
 * @argv:  array of command line arguments
 * Return:  0.
 */
int main(int argc, char **argv)
{
	stat d;
	(void)argc;
	init_data(&d, argv[0]);
	_exec(&d);

	return (0);
}
