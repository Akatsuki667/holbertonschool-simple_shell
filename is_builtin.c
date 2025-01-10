#include "simple_shell.h"
/**
  * is_builtin - determines if input matches built-in command
  * @builtin_flag: ptr to int (builtin flag)
  * @cmd_vector: char **cmd_vector, arr of ptrs : tokenized usr input
  * @line: usr input buffer
  * Return: void
  */
void is_builtin(int *builtin_flag, char **cmd_vector, char *line)
{
	if (strcmp(cmd_vector[0], "env") == 0)
	{
		_printenv();
		*builtin_flag = 1;
		return;
	}

	exit_handler(cmd_vector, line);
}
