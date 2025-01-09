#include "simple_shell.h"
/**
 * exec_cmd - exécution programme
 * @line: pointeur prompt user
 * @array: stockage buffer des tokens
 * @argv: nom du programme
 * Return: void
 */
void exec_cmd(char *line, char *array[1024], char *argv)
{
	pid_t pid; /* stockage processus */
	int status; /* stockage statut processus enfant */

	pid = fork(); /* création processus enfant */
	if (pid == -1) /* vérification échec processus */
	{
		printf("Je sors en echec fork\n");
		perror(argv);
		free(line); /* libération mémoire alloué à line par getline() */
		exit(EXIT_FAILURE); /* indication erreur */
	}
	else if (pid == 0) /* vérification processus enfant */
	{
		if (execve(line, array, environ) == -1) /* vérification exécution valide */
		{
			printf("Echec enfant\n");
			perror(argv);
			free(line); /* libération mémoire alloué à line par getline() */
			exit(EXIT_FAILURE); /* termine processus enfant avec erreur */
		}
	}
	else /* Sinon processus parent */
		wait(&status); /* instruction d'attente fin processus enfant */
}
