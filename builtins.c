#include "shell.h"
/**
 * handle_exit - Exits the shell
 * @args: Array of arguments
 * Return: 0
 */
void handle_exit(char **args)
{
	int status = 0;

	free(args);
	exit(status);
}

/**
 * handle_env - Prints the current environment variables
 * Return: 0
 */
void handle_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}

