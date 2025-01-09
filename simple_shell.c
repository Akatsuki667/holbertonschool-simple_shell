#include "simple_shell.h"
/**
 * main - Entry point, démarrage shell
 * @argc: nb arguments
 * @argv: pointeur liste arguments CLI
 * Return: 0 pour succès, 1 pour échec
 */
int main(int argc, char *argv[])
{
	char *line = NULL; /* pointeur stockage entrée utilisateur */
	size_t len = 0; /* taille buffer getline */
	int is_interactive = isatty(STDIN_FILENO);
	/* vérification stdin interactif */
	if (argc != 1) /* vérification nb arguments valide */
	{
		perror(argv[0]);
		return (1);
	}
	while (1) /* boucle infini shell */
	{
		if (is_interactive) /* vérification mode interactif */
		{
			printf("#c_is_hell "); /* affichage prompt */
			fflush(stdout); /* froce écriture imédiate prompt */
		}

		if (getline(&line, &len, stdin) == -1)
		/* vérification entrée utilisateur valide */
		{
			if (is_interactive) /* vérification mode interactif */
				printf("\n");

			break; /* stop boucle */
		}

		line[strcspn(line, "\n")] = '\0';

		if (strcmp(line, "env") == 0)
			_printenv();

		_tokenize(line, argv[0]); /* appel fonction */
	}
	free(line); /* libération mémoire alloué */
	return (0);
}
