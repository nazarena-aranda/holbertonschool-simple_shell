#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

char **tokenize_input(char *input);
void execute_command(char **args);
char *find_command_in_path(char *command);
void handle_exit(char **args);
void handle_env(void);
void execute_external_command(char **args);

#endif

