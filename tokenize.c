#include "shell.h"

/**
 * tokenize -  splits a string into smaller parts.
 * @uinput: Commands received from the user.
 * @stoken: store the tokens.
 * Return: return the number of tokens.
*/
char **tokenize(char *uinput, int *count)
{
char *delim = " \n";
char *token;
char **stoken = NULL;
char *buffercpy = strdup(uinput);

if (buffercpy == NULL)
{
return (NULL);
}

stoken = malloc(MAX_ARGS * sizeof(char *));

if (stoken == NULL)
{
free(buffercpy);
return (NULL);
}

token = strtok(buffercpy, delim);

*count = 0;
while (token != NULL)
{
stoken[*count] = strdup(token);
(*count)++;
token = strtok(NULL, delim);
}

stoken[*count] = NULL;
free(buffercpy);
return (stoken);
}
