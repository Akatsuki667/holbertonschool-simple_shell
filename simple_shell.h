#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h> /* input/outoput */
#include <stdlib.h> /* gestion mémoire/processus */
#include <string.h> /* manipulation chaîne de caractères */
#include <unistd.h> /* gestion fichiers/processus */
#include <sys/types.h> /* déclaration types spécifiques */
#include <sys/wait.h> /* founit macros/fonctions gestion processus enfant */

void _tokenize(char *str, char *argv);
void exec_cmd(char *line, char *array[1024], char *argv);
char *check_for_exe_in_path(char *array);

#endif
