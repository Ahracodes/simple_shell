#include "main.h"

/**
 * compare_strings - function to compare two strings of characters
 *
 * @a: first string
 *
 * @b: second string
 *
 * Return: difference between strings
 */
int compare_strings(char *a, char *b)
{
	while (*a && (*a == *b)) /* while a not null and a equal to b */
	{
		a++;
		b++;
	}
	return (*(char *)a - *(char *)b); /* diff between the two chars */
}


/**
 * copy_string - function that copies string from array to another
 *
 * @from: source of string
 *
 * @to: destination of string
 *
 * Return: pointee to copied string
 */

char *copy_string(char *to, const char *from)
{
	int x;

	for (x = 0; from[x] != '\0'; x++)
		to[x] = from[x]; /* iterate through string and copy it */

	to[x] = '\0';

	return (to);
}

/**
 * string_len - function that measures lenght of a string
 *
 * @entry: input string
 *
 * Return: Lenght of string
 */

unsigned int string_len(char *entry)
{
	unsigned int len = 0;

	while (entry[len] != '\0') /* while not null */
		lenght++;

	return (len);
}
