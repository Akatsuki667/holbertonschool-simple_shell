#include "simple_shell.h"
/**
  * free_cmd_vector - frees allocated memory to array of ptrs to args
  * @cmd_vector: array of ptrs to usr-inputted arguments
  * Return: void
  */
void free_cmd_vector(char **cmd_vector)
{
	int i;

	for (i = 0; cmd_vector[i] != NULL; i++)
		free(cmd_vector[i]);
	free(cmd_vector);
}
