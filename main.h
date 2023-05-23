#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>

/* prototypes */
char *new_getenv(char *varname);
void env_printing(void);
char *command_finder(char *cmmd,char *full_path, char *path);
int executer(char **tkn, char *prog, char *path);
char *copy_string(char *to, const char *from);
unsigned int string_len(char *entry);
int compare_strings(char *a, char *b);
void end_of_file(char *date);
int handle_whitespace(char *entry);
void clear_storage(char *strg, char **tkns, char *path);
void exiting(char *strg, char **tkns, int status);
int main(int argc, char *av[]);
char **tokenizer(char *str);

/* define */
#define MAX_SIZE 1024
#define DELIMITOR " \n\t\r\""
extern char **environ;

#endif
