#include "simple_shell.h"
/**
  * _printenv - builtin command printing environement variables
  * Return: void
  */
void _printenv(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
