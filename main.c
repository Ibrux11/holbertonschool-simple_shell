#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include "shell.h"

/**
 * main - Entry point of the shell program
 * Return: Always 0
 */
int main(void)
{
    char *command;

    while (1)
    {
        prompt();
        command = read_command();
        if (strcmp(command, "exit") == 0)
        {
            free(command);
            break;
        }
        execute_command(command);
        free(command);
    }

    return 0;
}