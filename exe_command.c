#include "shell.h"
/**
 * exeCommand - function to execute the user commmands
 *
*/

int exeCommand(char **stoken)
{
struct stat st;
char *excommand;
pid_t pchild;
int status = 0;

excommand = spath(stoken[0]);

if ((excommand == NULL) || stat(excommand, &st) != 0)
{
fprintf(stderr, "./hsh: 1: %s: not found\n", stoken[0]);
exit(127);
}

if (excommand != stoken[0])
{
free(stoken[0]);
stoken[0] = excommand;
}

pchild = fork();

if (pchild == -1)
return (1);

if (pchild != 0)
{
waitpid(pchild, &status, 0);

if (WIFSIGNALED(status))
{
int signal_number = WTERMSIG(status);
printf("Child process terminated by signal %d\n", signal_number);
}
if (status != 0)
return (2);

return (0);
}

if (execve(excommand, stoken, NULL) == -1)
return (1);

return (0);
}
