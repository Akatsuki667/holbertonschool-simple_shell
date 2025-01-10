#include "simple_shell.h"
/**
 * main - Entry point, démarrage shell
 * @argc: nb arguments
 * @argv: pointeur liste arguments CLI
 * Return: 0 pour succès, 1 pour échec
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *line = NULL; /* pointeur stockage entrée utilisateur */
	size_t len = 0; /* taille buffer getline */
	int is_interactive = isatty(STDIN_FILENO); /* init interactive flag */
	char **cmd_vector;
	int i;

	while (1) /* boucle infini shell */
	{
		if (is_interactive) /* vérification mode interactif */
		{
			printf("#c_is_hell "); /* affichage prompt */
			fflush(stdout); /* force écriture imédiate prompt */
		}
		if (getline(&line, &len, stdin) == -1)
		/* acquisition input user depuis input stream stdin */
		{
			if (is_interactive) /* vérification mode interactif */
				printf("\n");
			break; /* sort de la boucle while */
		}
		line[strcspn(line, "\n")] = '\0'; /* supp le \n final */

		cmd_vector = _tokenize(line, argv[0]);
		if (!cmd_vector)
			continue;

		if (cmd_vector[0][0] != '/') /* vérification PATH absolu ? */
			check_for_exe_in_path(cmd_vector[0], argv[0]);

		printf("%s\n", cmd_vector[0]);
		if (strcmp(cmd_vector[0], "env") == 0)
		{
			printf("%s\n", cmd_vector[0]);
			_printenv();
		}

		exec_cmd(cmd_vector, argv[0]);
		for (i = 0; cmd_vector[i] != NULL; i++)
			free(cmd_vector[i]); /* libération emplacements tableau */
		free(cmd_vector); /* libération tableau */
	}
	free(line);
	return (0);
}
