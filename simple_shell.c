#include "simple_shell.h"
/**
 * main - Entry point, démarrage shell
 * @argc: nb arguments
 * @argv: pointeur liste arguments CLI
 * Return: 0 pour succès, 1 pour échec
 */
int main(int argc, char *argv[])
{
	char *line = NULL; /*stockage pointeur entrée utilisateur */
	size_t len = 0; /* taille initiale buffer alloué */

	if (argc != 1) /* vérification validité nb argument */
	{
		perror(argv[0]);
		return (1);
	}

	while (1) /* boucle infini prompt */
	{
		if (isatty(STDIN_FILENO)) /* Vérifie exécution interactive */
		{
			printf("#cisfun$ "); /* affichage prompt */
			fflush(stdout); /* forcer écriture immédiate */
		}

		if (getline(&line, &len, stdin) == -1) /* vérification lecture a échoué */
		/* lire ligne d'entrée à partir de stdin(clavier) */
		{
			if (feof(stdin)) /* Gère le Ctrl + D */
			{
				if (isatty(STDIN_FILENO)) /* Si intéractif */
					printf("\n");
				break;
			}
			else /* Autres erreurs de getline */
			{
				perror(argv[0]);
				free(line); /* libération mémoire alloué à line par getline() */
				return (1); /* indication erreur */
			}
		}

		_tokenize(line, argv[0]);
	}
	free(line); /* libération mémoire alloué à line par getline() */
	return (0);
}
