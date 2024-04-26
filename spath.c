#include "shell.h"

char *spath(char *excommand)
{
char *path = getenv("PATH");
char *pathcpy, *delim, *rute = NULL;

if (path == NULL || *path == '\0')
{
if (access(excommand, X_OK) == 0)
{
return (excommand);
}
else
{
return (NULL);
}
}

pathcpy = strdup(path);

if (pathcpy == NULL)
{
return (NULL);
}

delim = strtok(pathcpy, ":");
while (delim != NULL)
{
size_t len = strlen(delim) + strlen(excommand) + 2;
rute = malloc(len);

if (rute == NULL)
{
free(pathcpy);
return (NULL);
}

sprintf(rute, "%s/%s", delim, excommand);

if (access(rute, X_OK) == 0)
{
free(pathcpy);
return (rute);
}

free(rute);
delim = strtok(NULL, ":");
}

free(pathcpy);
return (excommand);
}
