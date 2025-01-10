#include "simple_shell.h"
/**
  * _getenv - retrieves queried env variable
  * @name: variable asked for
  * Return: ptr to string containing all pathes to look exec files in
  */
char *_getenv(const char *name)
{
	int i = 0; /* index parcourir variable environnement */
	size_t j; /* index comparaison caractères */
	size_t len = strlen(name); /* longueur clé(name) */
	int flag = 0; /* indicateur de correspondance */

	while (environ[i]) /* parcours variable environnment */
	{
		for (j = 0; j < len; j++)
		/* comparaison caractères clé avec environ[i]*/
		{
			if (environ[i][j] != name[j])
			/* si pas de correspondance */
				break; /* arrêt comparaison */
		}
		if (j == len && environ[i][j] == '=')
		/* si correspondance et caractère suivant est "=" */
		{
			flag = 1; /* indique correspondance trouvé */
			break; /* arrêt boucle while */
		}
		i++; /* incrémentation variable environnement suivant */
	}
	return (flag == 1 ? &environ[i][j + 1] : NULL);
	/* retourn pointeur sur la valeur après "=" si correspondance */
}
