#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include "shell.h"

/**
 
prompt - Display the shell prompt*/
void prompt(void)
{
    printf("($) ");
}