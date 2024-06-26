#include "shell.h"

/**
 * _values_path - Separate the path into new strings.
 * @arg: Command input from the user.
 * @env: Environment.
 * Return: Pointer to strings.
 */
int _values_path(char **arg, char **env)
{
	char *token = NULL, *path_rela = NULL, *path_absol = NULL;
	size_t value_path, len;
	struct stat stat_lineptr;

	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);
	path_rela = _get_path(env);
	if (!path_rela)
		return (-1);
	token = strtok(path_rela, ":");
	len = _strlen(*arg);
	while (token)
	{
		value_path = _strlen(token);
		path_absol = malloc(sizeof(char) * (value_path + len + 2));
		if (!path_absol)
		{
			free(path_rela);
			return (-1);
		}
		path_absol = strcpy(path_absol, token);
		_strcat(path_absol, "/");
		_strcat(path_absol, *arg);

		if (stat(path_absol, &stat_lineptr) == 0)
		{
			*arg = path_absol;
			free(path_rela);
			return (0);
		}
		free(path_absol);
		token = strtok(NULL, ":");
	}
	token = '\0';
	free(path_rela);
	return (-1);
}
