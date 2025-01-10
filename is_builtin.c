#include "simple_shell.h"
/**
  * is_builtin - determines if input matches built-in command
  * @builtin_flag: ptr to int (builtin flag)
  * @cmd_vector_item: ptr to user input builtin
  * Return: void
  */
void is_builtin(int *builtin_flag, char *cmd_vector_item)
{
	if (strcmp(cmd_vector_item, "env") == 0)
	{
		_printenv();
		*builtin_flag = 1;
		return;
	}
}
