#include "shell.h"

int main(void)
{
	char *input = NULL; /*Guarda lo que dijo el usuario*/
	size_t len = 0;
	ssize_t read;

	while (1) /* Bucle infinito */
	{
		printf("#cisfun$ "); /*Mostramos el prompt*/
		read = getline(&input, &len, stdin); /*Leemos lo que nos dijo el usuario en el prompt*/

		if (read == -1) /*Ctrl+D o EOF*/
		{
			printf("\n");
			break;
		}
	}

	free(input); /* Liberamos memoria */
	return (0);
}
