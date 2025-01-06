#include "simple_shell.h"
/**
 * _tokenize - tokénisation argument ligne de commande
 * @str: string à tokéniser
 * @argv: nom du programme pour message erreur
 */
void _tokenize(char *str, char *argv)
{
	pid_t pid; /* stockage pid renvoyé par fork */
	int status, i;
	char *token;
	char *delim = " \n";
	char *array[1024]; /* stockage mot extrait */

	token = strtok(str, delim); /* découpage line en sous chaîne */
	i = 0;
	while (token) /* tant que mots à extraire */
	{
		array[i++] = token; /* stockage de chaque mot trouvé */
		token = strtok(NULL, delim); /* appel pour continuer analyse line */
	}
	array[i] = NULL;
	/* Arrête la liste d'arguments i avec le char null */

	pid = fork(); /* création processus enfant */
	if (pid == -1) /* vérification échec processus */
	{
		perror(argv);
		free(str); /* libération mémoire alloué à line par getline() */
		exit(EXIT_FAILURE); /* indication erreur */
	}
	else if (pid == 0) /* vérification processus enfant */
	{
		if (execve(array[0], array, NULL) == -1)
		/* vérification exécution valide */
		{
			perror(argv);
			free(str); /* libération mémoire alloué à line par getline() */
			exit(EXIT_FAILURE); /* termine processus enfant avec erreur */
		}
	}
	else /* Sinon processus parent */
		wait(&status); /* instruction pour ce dernier */
}
