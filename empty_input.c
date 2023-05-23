#include "main.h"

/** endoffile_handler - buffer is endoffile
 * @data: string
 * Return: void
 */

void end_of_file(char *data)
{
	if(data != NULL)
	{
		free(data);
		data = NULL;
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	exit(0);
}


/* whitespace_handler 
@c: string
Return: O or 1 */

int handle_whitespace(char *entry)
{
	int x;
	char y;

	for (x = 0; entry[x] != '\0'; x++)
	{	
		y = entry[x];
		if (!isspace(y))
			return (0);
	}
	return (1);
}
