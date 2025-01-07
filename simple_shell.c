#include "simple_shell.h"
/**
 * main - Entry point, démarrage shell
 * @argc: nb arguments
 * @argv: pointeur liste arguments CLI
 * Return: 0 pour succès, 1 pour échec
 */
int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	int is_interactive = isatty(STDIN_FILENO);

	if (argc != 1)
	{
		perror(argv[0]);
		return (1);
	}

	while (1)
	{
		if (is_interactive)
		{
			printf("#cisfun$ ");
			fflush(stdout);
		}
		if (getline(&line, &len, stdin) == -1)
		{
			if (is_interactive)
				printf("\n");
			break;
		}

		if (strncmp(line, "exit", 4) == 0)
			break;

		_tokenize(line, argv[0]);
	}
	free(line);
	return (0);
}
