#include "main.h"

/* add env_printing:wq */

/**
 * new_getenv - retrieves environment variable
 *
 * @varname: of variable
 *
 * Return: pointer to environ variable
 */

char *new_getenv(char *varname)
{
	char *value = NULL;
	int a = 0, b = 0, destindex = 0;
	char *z;

	while (environ[a] != NULL)
	{
		while (environ[a][b] != '=')
		{
			if (environ[a][b] != varname[b])
				break;
			b++;
		}

		if (environ[a][b] == '=' && varname[b] == '\0')
		{
			value = environ[a];
			destindex = b + 1;
			break;
		}

		a++;
	}
	z = (value + destindex);
	return (z);
}

/**
 * env_printing - prints the environment var
 *
 * Return: void
 */

void env_printing(void)
{
	char **s;
	size_t lenght;

	for (s = environ; *s != NULL; s++)
	{
		lenght = string_len(*s);
		write(STDOUT_FILENO, *s, lenght);
		write(STDOUT_FILENO, "\n", 1);
	}
}
