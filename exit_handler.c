#include "simple_shell.h"
/**
  * exit_handler - sets up exit builtin command
  * @cmd_vector: char **cmd_vector from main, tokenized usr input
  * @line: usr input buffer
  * Return: void
  */
void exit_handler(char **cmd_vector, char *line)
{
	if (cmd_vector)
		free_cmd_vector(cmd_vector);
	if (line)
		free(line);
	exit(EXIT_SUCCESS);
}
