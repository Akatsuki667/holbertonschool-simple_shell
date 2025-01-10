#include "simple_shell.h"
/**
  * exit_handler - sets up exit builtin command
  * @cmd_vector: char **cmd_vector from main, tokenized usr input
  * @line: usr input buffer
  * Return: void
  */
void exit_handler(char **cmd_vector, char *line)
{
	free_cmd_vector(cmd_vector);
	free(line);
	exit(EXIT_SUCCESS);
}
