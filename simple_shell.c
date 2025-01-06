#include <stdio.h> /* input/outoput */
#include <stdlib.h> /* gestion mémoire/processus */
#include <string.h> /* manipulation chaîne de caractères */
#include <unistd.h> /* gestion fichiers/processus */
#include <sys/types.h> /* déclaration types spécifiques */
#include <sys/wait.h> /* founit macros/fonctions gestion processus enfant */

int main(int argc, char *argv[])
{
	pid_t pid; /* stockage pid renvoyé par fork */
	int status; /* stockage status fin de processus enfant */

	char *line = NULL; /*stockage pointeur entrée utilisateur */
	size_t len = 0; /* taille initiale buffer alloué */
	char *token; /* stockage pointeur mot extrait par strtok */
	char *delim = " \n"; /* délimitateur de mot */
	int i; /* index écrire dans le tableau */
	char *array[1024]; /* stockage mot extrait */

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

		if (getline(&line, &len, stdin) == - 1) /* vérification lecture a échoué */
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

		i = 0;
		token = strtok(line, delim); /* découpage line en sous chaîne */
		while (token) /* tant que mots à extraire */
		{
			array[i++] = token; /* stockage de chaque mot trouvé */
			token = strtok(NULL, delim); /* appel pour continuer analyse line */
		}
		array[i] = NULL; 
		/* Arrête la liste d'arguments i avec le char null */

		if (array[0] == NULL)
			continue;

		pid = fork(); /* création processus enfant */
		if (pid == - 1) /* vérification échec processus */
		{
			perror(argv[0]);
			free(line); /* libération mémoire alloué à line par getline() */
			return (1); /* indication erreur */
		}
		else if (pid == 0) /* vérification processus enfant */
		{
			if (execve(array[0], array, NULL) == -1)
			/* vérification exécution valide */
			{
				perror(argv[0]);
				free(line); /* libération mémoire alloué à line par getline() */
				exit(EXIT_FAILURE); /* termine processus enfant avec erreur */
			}
		}
		else /* Sinon processus parent */
		{
			wait(&status); /* instruction pour ce dernier */
		}
	}	
	free(line); /* libération mémoire alloué à line par getline() */
	return (0);
}
