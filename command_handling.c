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
 * Return: NULL
 */

char* command finder(char *cmmd, char* fullpath, char* path)
