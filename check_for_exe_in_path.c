#include "simple_shell.h"
/**
 * check_for_exe_in_path - chercher exécutable
 * @array: exécutable donner par le user
 * Return: Retourne exécutbale si succès, retourne NULL si échec
 */
char *check_for_exe_in_path(char *array, char *argv)
{
	char *path, *path_copy, *path_token, *possible_path, *path_delim = ":";
	size_t pp_len;

	if (array == NULL) /* vérification paramètre valide */
		return (NULL);
	path = getenv("PATH"); /* chercher variable d'environnement */
	if (!path) /* vérification variable existe */
	{
		fprintf(stderr, "Error : PATH environment variable not found\n");
		return (NULL); /* exit ? */
	}
	path_copy = strdup(path); /* copie variable d'environnemnt */
	if (!path_copy) /* vérification copie existante */
	{
		fprintf(stderr, "Error : PATH handling error\n");
		return (NULL);
	}
	path_token = strtok(path_copy, path_delim);/* segmentation path */
	while (path_token)
	{
		pp_len = strlen(path_token) + strlen(array) + 2; /* + 2 pour /,'\0' */
		possible_path = malloc(pp_len); /* allocation mémoire */
		if (!possible_path) /* vérification alloc n'a pas fail */
		{
			free(path_copy);
			return (NULL);
		}
		snprintf(possible_path, pp_len, "%s/%s", path_token, array);
		/* reconstruction path absolu valide */
		if (!access(possible_path, X_OK)) /* vérif ficher exec trouvé ? */
		{
			free(path_copy);
			return (possible_path); /* retourne path absolu */
		}
		free(possible_path);
		path_token = strtok(NULL, path_delim); /* incrémentation segment */
	}
	perror(argv);
	free(path_copy);
	return (NULL);
}
