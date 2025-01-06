#include "shell.h"

/**
 * execute_command - Executes a given command or built-in
 * @args: Array of arguments for the command
 * Return: 0
 */

void execute_command(char *command, char **args) 
{
	if (access(command, X_OK) != 0) 
	{
	if (errno == ENOENT)
	{
		fprintf(stderr, "%s: not found\n", command);
		exit(127);
        } 
	else 
	{
		perror(command);
		exit(1);
	}
	}

	execvp(command, args);

	perror(command);
	exit(1);
}


/**
 * execute_external_command - Executes non-built-in commands
 * @args: Array of arguments for the command
 * Return: 0
 */
void execute_external_command(char **args)
{
	pid_t pid;
	char *command_path = args[0];

	if (access(command_path, X_OK) != 0)
	{
		command_path = find_command_in_path(args[0]);
		if (!command_path)
		{
			perror("./hsh");
			return;
		}
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(command_path, args, environ) == -1)
		{
			perror("Error");
			exit(1);
		}
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror("Fork error");
	}

	if (command_path != args[0])
		free(command_path);
}

