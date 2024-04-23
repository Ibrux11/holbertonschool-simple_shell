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
    char **args;
    int arg_count = 0;
    pid_t pid;
    int status;
    char *token;

    args = malloc(sizeof(char*) * 64);
    if (args == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    token = strtok(command, " ");
    while (token != NULL)
    {
        args[arg_count++] = token;
        token = strtok(NULL, " ");
    }
    args[arg_count] = NULL;

    if (strcmp(args[0], "cd") == 0)
    {
        free(args);
        return;
    }

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror(args[0]);
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

    free(args);
}
