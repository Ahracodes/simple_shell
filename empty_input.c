#include "main.h"

/**
<<<<<<< HEAD
 * end_of_file - data is end_of_file
 * condition ctrl+D
 * @data: string
=======
 * end_of_file - handle ctrl d (EOF)
 *
 * @data: entry string
 *
>>>>>>> 81b3243bef7463af79f7cb7737dec5cb37d0146d
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
<<<<<<< HEAD
 * handle_whitespace - check if there's space
 * @c: string
 * Return: 0 or 1
*/
=======
 * handle_whitespace - check if there's only space
 *
 * @entry: string
 *
 * Return: O or 1
 */
>>>>>>> 81b3243bef7463af79f7cb7737dec5cb37d0146d

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
