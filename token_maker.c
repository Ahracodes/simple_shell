#include "main.h"

/**
 * tokenizer - makes tokens out of command
 *
 * @str: input command
 *
 * Return: the tokens
 */

char **tokenizer(char *str)
{
	char **tkns, *tkn;
	int x;

	x = 0;
	tkns = (char **)malloc(sizeof(char *) * (MAX_SIZE + 1));

	if (tkns == NULL) /*mem alloc fail */
		exit(1);

	tkn = strtok(str, DELIMITOR); /* splits str at delimiter */
	if (tkn == NULL)
		return (NULL);

	while (tkn != NULL && x < MAX_SIZE) /* no more tkn or reach max size */
	{
		tkns[x++] = tkn;
		tkn = strtok(NULL, DELIMITOR);
	}

	tkns[x] = NULL;
	return (tkns);
}
