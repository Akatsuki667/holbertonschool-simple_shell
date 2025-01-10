#include "simple_shell.h"
/**
 * _tokenize - tokénisation argument ligne de commande
 * @line: string à tokéniser
 * @argv: nom du programme pour message erreur
 * Return: Tableau de pointeurs(args = tokens input user)
 */
char **_tokenize(char *line, char *argv)
{
	int i; /* index token extraits */
	char *token; /* pointeur token extrait de line */
	char *delim = " \t\r"; /* délimitateurs */
	char **cmd_vector; /* stockage mot extrait */

	if (line == NULL) /* vérification paramètre valide */
		return (NULL);
	cmd_vector = malloc(MAX_ARGS_INPUT * sizeof(char *));
	if (!cmd_vector)
	{
		perror(argv);
		return (NULL);
	}
	token = strtok(line, delim); /* découpage line en sous-chaînes */
	i = 0;
	while (token) /* pour tout argument non null */
	{
		cmd_vector[i] = malloc(PATH_MAX);/* make room for path */
		if (!cmd_vector[i])
		{
			while (i > 0)
				free(cmd_vector[i--]);
		free(cmd_vector);
		perror(argv);
		return (NULL);
		}
		strcpy(cmd_vector[i], token); /* copie token dans emplacement alloué */
		i++; /* incrémentation emplacement tableau */
		token = strtok(NULL, delim); /* incrementation - tok suivant */
	}
	cmd_vector[i] = NULL; /* Arrête liste d'args à idx[i] avec ptr null */

	if (cmd_vector[0] == NULL) /* vérification saisie utilisateur */
	{
		free(cmd_vector);
		return (NULL);
	}
	return (cmd_vector); /* retour tableau ptr contenant token saisi user */
}
