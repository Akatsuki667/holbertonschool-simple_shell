#include "simple_shell.h"
/**
 * _tokenize - tokénisation argument ligne de commande
 * @line: string à tokéniser
 * @argv: nom du programme pour message erreur
 */
void _tokenize(char *line, char *argv)
{
	int i;
	char *token;
	char *delim = " \n";
	char *array[1024]; /* stockage mot extrait */

	if (line == NULL)
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
	if (array[0] == NULL)
		return;
	exec_cmd(line, array, argv);

}
