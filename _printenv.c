#include "simple_shell.h"

void _printenv(void)
{
	char **env = environ;

	while(*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
