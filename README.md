# Minimalist Shell

## Introduction

This project consists of a minimalist shell written in C language, capable of executing system commands and built-in commands. It was developed as part of a course on operating systems to illustrate the basic concepts of Unix shells.

## Features

- Execution of system commands such as `ls`, `cat`, `echo`, etc.
- Implementation of built-in commands: `cd`, `help`, `exit`.
- Handling of Ctrl+D signals for shell exit.
- Display of environment with the `env` command.

## Compilation and Execution

### Compilation

To compile the program, execute the following command:

```bash
$ gcc -Wall -Werror -Wextra -pedantic *.c -o shell

## Execution

To launch the shell, execute the following command:

$ ./shell

## Built-in Commands

cd [directory]
Change the current working directory.

$ cd /path/to/directory

help
Displays help with a list of available built-in commands.

$ help

exit
Exits the shell.

$ exit

## Usage Examples

$ ./shell
$ ls
a.out  bypass.c  execute.c  getenv.c  getpath.c  hell.c  shell.c  shell.h  tokenize.c  values.c
$ cd ..
$ ls
shell-minimalist
$ exit

## Contributors

Ibrahim Hassan Ali

Esteban Guillen

## License


This project is licensed under the MIT License. See the LICENSE file for details.

