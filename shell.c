#include "main.h"


/**
 * clear_storage - cleans up
 *
 * @strg: buffer content
 *
 * @tkns: tokens stored
 *
 * @path: the path
 *
 * Return: NULL
 */
void clear_storage(char *strg, char **tkns, char *path)
{
	free(strg);
	free(tkns);
	free(path);
}

/**
 * exiting - handles exit
 *
 * @strg: buffer content
 *
 * @tkns: tokens stored
 *
 * @status: exit status
 *
 * Return: NULL
 */
void exiting(char *strg, char **tkns, int status)
{
	free(strg);
	free(tkns);
	exit(status);
}

/**
 * main - the command line interpreter base
 *
 * @argc: command line arguments count
 *
 * @av: program name
 *
 * Return: 0
 */
int main(int argc, char *av[])
{	char *strg = NULL, *env_of_path, *path, **tkns;
	int stat = 0, fl = 0, lenght = 0;
	size_t strg_s = 0;
	(void) argc;

	while (1)
	{
		if (isatty(0))
			write(STDOUT_FILENO, "$ ", 2);
		lenght = getline(&strg, &strg_s, stdin);
		if (lenght == EOF)
			end_of_file(strg);
		if (lenght == -1)
		{	clear_storage(strg, NULL, NULL);
			exit(0); }
		if (*strg == '\n')
		{	clear_storage(strg, NULL, NULL);
			continue; }
		strg[lenght - 1] = '\0';

		if (handle_whitespace(strg) == 1)
			continue;
		tkns = tokenizer(strg);
		if (compare_strings(tkns[0], "env") == 0)
		{	free(tkns);
			env_printing();
			continue; }
		if (compare_strings(tkns[0], "exit") == 0)
			exiting(strg, tkns, stat);
		env_of_path = new_getenv("PATH");
		path = command_finder(tkns[0], path, env_of_path);
		if (path == NULL)
			path = tkns[0];
		else
			fl = 1;
		stat = executer(tkns, av[0], path);
		clear_storage(strg, tkns, (fl == 1) ? path : NULL);
		strg = NULL;
		strg_s = 0; }
	return (0); }
