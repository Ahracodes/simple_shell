#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/* prototypes */
char *new_getenv(char *varname);
char *command_finder(char *cmmd, char *path);
int executer(char **tkn, char *prog, char *path);
char *copy_string(char *to, const char *from);
unsigned int string_len(char *entry);
int compare_strings(char *a, char *b);

/* define */
#define MAX_SIZE 1024
