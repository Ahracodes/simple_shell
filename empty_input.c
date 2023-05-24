#include "main.h"

/**
 * end_of_file - handle ctrl d (EOF)
 *
 * @data: entry string
 *
 * Return: void
 */

void end_of_file(char *data)
{
	if (data != NULL)
	{
		free(data);
		data = NULL; /*set data to NULL */
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	exit(0);
}


/**
 * handle_whitespace - check if there's only space
 *
 * @entry: string
 *
 * Return: O or 1
 */
int handle_whitespace(char *entry)
{
	int x;
	char y;

	for (x = 0; entry[x] != '\0'; x++)
	{
		y = entry[x];
		if (!isspace(y)) /* checks if whitespace */
			return (0);
	}
	return (1); /* if only whitespace */
}
