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

	int is_interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_interactive)
			printf("#cisfun$ ");

		read = getline(&input, &len, stdin);
		if (read == -1)
		{
			if (is_interactive)
				printf("\n");
			break;
		}

		args = tokenize_input(input);
		if (!args || !args[0])
		{
			free(args);
			continue;
		}

		execute_command(args, input);
		free(args);
	}

	free(input);
	return (0);
}
