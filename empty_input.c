#include "main.h"

/** endoffile_handler - buffer is endoffile
 * @data: string
 * Return: void
 */




void endoffile(char *data)
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
Return: O or 1*/
int whitespace(char *c)

	int x;
	char y;

	for (x = 0; c[x] != '\0'; x++)
{
	y = c[x];
	if (!isspace(y))
		return (0);
}
return (1)
	}
