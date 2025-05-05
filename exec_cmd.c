#include "simple_shell.h"
/**
 * exec_cmd - exécution programme
 * @line: pointeur prompt user
 * @array: stockage buffer des tokens
 * @argv: nom du programme
 * Return: void
 */
void exec_cmd(char **cmd_vector, char *argv)
{
	pid_t pid; /* stockage processus */
	int status; /* stockage statut processus enfant */

	pid = fork(); /* création processus enfant */
	if (pid == -1) /* vérification échec processus */
	{
		perror(argv);
		return;
	}
	else if (pid == 0) /* vérification processus enfant */
	{
		if (execve(cmd_vector[0], cmd_vector, NULL) == -1) 
		/* vérif execution valide */
		{
			perror(argv);
			exit(EXIT_FAILURE);
		}
	}
	else /* Sinon processus parent */
		wait(&status); /* instruction d'attente fin processus enfant */
}
