#include "simple_shell.h"
/**
 * _tokenize - tokénisation argument ligne de commande
 * @line: string à tokéniser
 * @argv: nom du programme pour message erreur
 */
void _tokenize(char *line, char *argv)
{
	int i; /* index token extraits */
	char *token; /* pointeur token extrait de line */
	char *delim = " \n"; /* délimitateurs */
	char *array[1024]; /* stockage mot extrait */
	char *cmd_path;

	if (line == NULL) /* vérification paramètre valide */
		return;

	token = strtok(line, delim); /* découpage line en sous chaîne */
	i = 0;
	while (token) /* tant que mots à extraire */
	{
		array[i++] = token; /* stockage de chaque mot trouvé */
		token = strtok(NULL, delim); /* appel pour continuer analyse line */
	}

	array[i] = NULL;
	/* Arrête la liste d'arguments i avec le char null */

	if (array[0] == NULL) /* vérification saisie utilisateur */
		return;

	if (array[0][0] != '/') /* user a saisi path absolu ? */
	{
		cmd_path = check_for_exe_in_path(array[0]); /* a saisi un exécutable */
		/* possible_path vérifié devient cmd_path(retour fonction) */
		if (!cmd_path) /* vérification existence cmd_path */
			return;
		exec_cmd(cmd_path, array, argv); /* appel fonction d'exécution */
		free(cmd_path); /* libération mémoire */
	}
	else /* sinon a saisi un path absolu */
		exec_cmd(line, array, argv);
}
