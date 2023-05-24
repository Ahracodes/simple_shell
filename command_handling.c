#include "main.h"

/**
 * executer - function that executes given commands
 *
 * @tkn: array for tokens of the commands and its arguments
 *
 * @prog: program's name
 *
 * @path: path of the executable file handled
 *
 * Return: exit status of the child process
 */

int executer(char **tkn, char *prog, char *path)
{
	pid_t child_pid;
	int exit_stat; /*exit status for program */

	child_pid = fork(); /* create child process */

	if (child_pid == 0)
	{
		if (execve(path, tkn, environ) == -1) /* indicates error */
		{
			perror(prog);
			exit(2);
		}
	}
	else if (child_pid < 0) /* forking failed */
	{
		perror(prog);
		exit(1);
	}
	else /* code executed */
		wait(&exit_stat); /* wait for end of processing */
	return (exit_stat);
}


/**
 * command_finder - searches for the command in PATH environ
 *
 * @cmmd: command name
 *
 * @full_path: full path string
 *
 * @path: the search path
 *
 * Return: NULL
 */

char *command_finder(char *cmmd, char *full_path, char *path)
{
	unsigned int lenght_of_cmmd, lenght_of_path;
	char *tkn, *copy_of_path;
	int X;

	lenght_of_cmmd = string_len(cmmd);
	copy_of_path = malloc(sizeof(char) * (string_len(path) + 1));
	copy_string(copy_of_path, path);
	tkn = strtok(copy_of_path, ":"); /* tokenize with : as delimiter */

	while (tkn != NULL) /* iterate through all tokens */
	{
		lenght_of_path = string_len(tkn);
		X = lenght_of_path + lenght_of_cmmd + 2;
		full_path = malloc(sizeof(char) * (X));

		if (full_path == NULL) /* mem alloc fail */
		{
			free(copy_of_path);
			return (NULL);
		}

		copy_string(full_path, tkn);
		full_path[lenght_of_path] = '/'; /* append / to fp */
		copy_string(full_path + lenght_of_path + 1, cmmd); /* append cmmd to fp */
		full_path[lenght_of_path + lenght_of_cmmd + 1] = '\0'; /* add \0 to fp */

		if (access(full_path, X_OK) != 0) /* access and executable check */
		{
			free(full_path);
			full_path = NULL;
			tkn = strtok(NULL, ":");
		}
		else
			break;
	}
	free(copy_of_path);
	return (full_path);
}
