#include "shell.h"
/**
 * handle_exit - Exits the shell
 * @args: Array of arguments
 * @input: Buffer
 * Return: 0
 */
void handle_exit(char **args, char *input)
{
	if (args)
		free(args);
	if (input)
		free(input);
	exit(0);
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

