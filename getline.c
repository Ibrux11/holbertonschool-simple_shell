#include "shell.h"

/**
 * _getline_command - Get user input from standard input
 *
 * Return: On success, returns a pointer to the input line.
 *         On failure, returns NULL.
 */
char *_getline_command(void)
{
	char *lineptr = NULL;
	size_t charter_user = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	if (getline(&lineptr, &charter_user, stdin) == -1)
	{
		free(lineptr);
		return (NULL);
	}

	return (lineptr);
}
