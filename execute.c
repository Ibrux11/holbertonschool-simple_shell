execute.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include "shell.h"

/**
 * execute_command - Execute the command entered by the user
 * @command: Pointer to the command string
 */
void execute_command(char *command)
{
    char *args[2];
    pid_t pid;
    int status;

    if (strcmp(command, "cd") == 0)
    {
        char *home_dir = getenv("HOME");
        if (home_dir == NULL)
        {
            fprintf(stderr, "cd: No HOME environment variable\n");
            return;
        }
        if (chdir(home_dir) != 0)
        {
            perror("cd");
        }
        return;
    }

    args[0] = command;
    args[1] = NULL;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        if (execve(command, args, NULL) == -1)
        {
            perror(command);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        do
        {
            if (waitpid(pid, &status, WUNTRACED) == -1)
            {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}