#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <limits.h> /* For PATH_MAX */
#include <stdio.h> /* input/output */
#include <stdlib.h> /* gestion mémoire/processus */
#include <string.h> /* manipulation chaîne de caractères */
#include <unistd.h> /* gestion fichiers/processus */
#include <sys/types.h> /* déclaration types spécifiques */
#include <sys/wait.h> /* founit macros/fonctions gestion processus enfant */

#define MAX_ARGS_INPUT 100


void exec_cmd(char **cmd_vector, char *argv);
void check_for_exe_in_path(char *cmd_vector_item, char *argv);
void _printenv(void);

char **_tokenize(char *line, char *argv);
char *_getenv(const char *name);

extern char **environ;

#endif
