#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * read_command - Read a command from stdin
 * Return: Pointer to the command string read
 */
char *read_command(void)
{
    size_t buffer_size = BUFFER_SIZE;
    ssize_t bytes_read;
    char *buffer = malloc(sizeof(char) * buffer_size);
    
    if (!buffer)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter command: ");
    bytes_read = getline(&buffer, &buffer_size, stdin);
    if (bytes_read == -1)
    {
        if (feof(stdin))
        {
            printf("\n");
            exit(EXIT_SUCCESS);
        }
        perror("read_command");
        exit(EXIT_FAILURE);
    }
    
    if (bytes_read > 0 && buffer[bytes_read - 1] == '\n')
        buffer[bytes_read - 1] = '\0';

    return buffer;
}
