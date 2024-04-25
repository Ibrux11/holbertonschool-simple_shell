#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include "shell.h"

/**
 * read_command - Read a command from stdin
 * Return: Pointer to the command string read
 */
char *read_command(void)
{
    size_t buffer_size = 0;
    ssize_t bytes_read;
    char *buffer = NULL;
    
    if (isatty(fileno(stdin))) {
        printf("#cisfun$ ");
        fflush(stdout);
    }

    bytes_read = getline(&buffer, &buffer_size, stdin);
    if (bytes_read == -1)
    {
        if (isatty(fileno(stdin))) {
            printf("\n");
        }
        free(buffer);
        exit(EXIT_SUCCESS);
    }
    
    if (bytes_read > 0 && buffer[bytes_read - 1] == '\n')
        buffer[bytes_read - 1] = '\0';

    return buffer;
}
