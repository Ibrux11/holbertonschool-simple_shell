#include "shell.h"
/**
 * simple_shell - shell
 * return: return 0 if sucess
*/

int main()
{
int status = 0, num, i;
char **stoken, *buffer;

while (1)
{

if (isatty(STDIN_FILENO) == 1)
{
printf("#cisfun$ ");
}

buffer = readInput();
if (strcmp(buffer, "env") == 0 || strcmp(buffer, "printenv") == 0)
{
free(buffer);
checkfunc();
return (0);
}
if (strcmp(buffer, "exit") == 0)
{
free(buffer);
break;
} 
stoken = tokenize(buffer, &num);

if (num > 0)
status = exeCommand(stoken);
for (i = 0; stoken[i] != NULL; i++)
{
free(stoken[i]);
}
free(stoken);
free(buffer);
}
return (status);
}
