#include "shell.h"
/**
 * tokenize_input - Splits user input into an array of arguments
 * @input: User input string
 * Return: Array of strings (tokens) or NULL on failure
 */
char **tokenize_input(char *input)
{
	char **tokens = NULL;
	char *token;
	size_t i = 0;

	tokens = malloc(sizeof(char *) * 64);
	if (!tokens)
		return (NULL);

	token = strtok(input, " \n");
	while (token)
	{
		tokens[i++] = token;
		token = strtok(NULL, " \n");
	}
	tokens[i] = NULL;
	return (tokens);
}