#ifndef MAIN_H
#define MAIN_H


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

#define MAX_ARGS 1024


char *readInput();
char **tokenize(char *uinput, int *count);
int exeCommand(char **stoken);
char *spath(char *excommand);
void checkfunc();

#endif
