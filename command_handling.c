#include "main.h"

/**
 * executer - function that executes given commands
 *
 * @tkn: array for tokens of the commands and its arguments
 *
 * @prog: the program name
 *
 * @path: path of the executable file handled
 *
 * Return: exit status of the child process
 */

int executer(char **tkn, char *prog, char *path)
{
	pid_t child_pid;
	int exit_stat;

	child_pid = fork();

	if (pid == 0)
	{
		if (execve(path, tkn, environ) == -1)
		{
			perror(prog);
			exit(2);
		}
	}
	else if (child_pid < 0)
	{
		perror(prog);
		exit(1);
	}
	else
		wait(&exit_status);
	return (exit_status);
}


/**
 * command_finder - searches for the command in PATH environ
 *
 * @cmmd: command name
 *
 * @path: the search path
 *
 * Return: NULL
 */

char *command_finder(char *cmmd, char *path)
{
	unsigned int lenght_of_cmmd, lenght_of_path;
	char *tkn, *full_path;

	full_path = NULL;
	lenght_of_cmmd = string_len(cmmd);
	tkn = strtok(path, ":");

	while (token != NULL)
	{
		lenght_of_path = string_len(tkn);
		X = lenght_of_path + lenght_of_cmmd + 2;
		full_path = malloc(sizeof(char) * (X));

		if (full_path == NULL)
			return (NULL);

		copy_string(full_path, tkn);
		full_path[lenght_of_path] = '/';
		copy_string(full_path + lenght_of_path + 1, cmmd);
		full_path[lenght_of_path + lenght_of_cmmd + 1] = '\0';

		if (access(full_path, X_OK) == 0)
			break;
		free(full_path);
		full_path = NULL;
		tkn = strtok(NULL, ":");
	}
	return (full_path);
}
