#include "shell.h"
/**
 * main - entry point
 * Return: 0
 */

int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;
	char **args;

	while (1)
	{
		printf("#cisfun$ ");
		read = getline(&input, &len, stdin);

		if (read == -1)
		{
			printf("\n");
			break;
		}

		args = tokenize_input(input);

		if (!args || !args[0])
		{
			free(args);
			continue;
		}

		execute_command(args);
		free(args);
	}

	free(input);
	return (0);
}
