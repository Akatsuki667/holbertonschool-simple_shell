#include "simple_shell.h"
/**
 * check_for_exe_in_path - chercher exécutable
 * @array: exécutable donner par le user
 * @argv: nom du programme CLI
 * Return: Retourne exécutbale si succès, retourne NULL si échec
 */
void check_for_exe_in_path(char *cmd_vector_item, char *argv)
{
	char *path, *path_copy, *path_token, *possible_path, *path_delim = ":";
	size_t pp_len;

	path = _getenv("PATH"); /* chercher variable d'environnement */
	if (!path) /* vérification variable existe */
	{
		fprintf(stderr, "%s: PATH variable not found\n", argv);
		return;
	}
	path_copy = strdup(path); /* copie variable d'environnemnt */
	if (!path_copy) /* vérification copie existante */
	{
		fprintf(stderr, "%s: PATH handling error\n", argv);
		return;
	}
	path_token = strtok(path_copy, path_delim);/* segmentation path */
	while (path_token)
	{
		pp_len = strlen(path_token) + strlen(cmd_vector_item) + 2; 
		/* + 2 pour /,'\0' */
		possible_path = malloc(pp_len);
		if (!possible_path) /* vérification alloc n'a pas fail */
		{
			free(path_copy); /* si fail */
			return;
		}
		sprintf(possible_path, "%s/%s", path_token, cmd_vector_item);
		/* reconstruction path absolu valide */
		if (!access(possible_path, X_OK)) /* vérif ficher exec trouvé ? */
		{
			strcpy(cmd_vector_item, possible_path);
			free(possible_path);
			free(path_copy);
			return;
		}
		free(possible_path);
		path_token = strtok(NULL, path_delim); /* incrémentation segment */
	}
	free(path_copy);
}
