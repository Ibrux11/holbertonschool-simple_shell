#include "shell.h"
/**
*
*/

void checkfunc()
{
int i = 0;

char **env = environ;

for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}
