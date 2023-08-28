#include "monty.h"
/**
 * _readop - function that reads opcode and argument from file
 * @fd: file descriptor to read from
 * Return: array containing the opcode, argument, and end flag
 */
char **_readop(int fd)
{
	char **r = NULL;

	r = initia_arr();
	read_process(fd, r);
	return (r);
}
/**
 * initia_arr - Initializes and allocates memory for arrays
 * @void: No parameters
 * Return: Pointer to an array containing opcode, argument, and end flag
 */
char **initia_arr(void)
{
	char **r = NULL;

	r = (char **)malloc(sizeof(char **) * 3);
	if (r == NULL)
		error_on_allocation();
	r[0] = malloc_arr();
	r[1] = malloc_arr();
	r[2] = malloc(1);
	if (r[0] == NULL || r[1] == NULL || r[2] == NULL)
		error_on_allocation();
	r[2][0] = '0';
	return (r);
}
/**
 * malloc_arr - Allocates memory for an array
 * @void: No parameters
 * Return: Pointer to the allocated array
 */
char *malloc_arr(void)
{
	int array_s = 100;
	char *array = NULL;

	array = malloc(array_s);
	if (array == NULL)
		error_on_allocation();
	for (int i = 0; i < array_s; i++)
		array[i] = 0;
	return (array);
}

/**
 * read_process - Reads characters from the file and processes them
 * @fd: file descriptor to read from
 * @r: array containing opcode, argument, and end flag
 * Return: No return value
 */
void read_process(int fd, char **r)
{
	int idx = 0, fl = 1, in_w = 0, word_c = 0;
	char c = 0;

	while (fl)
	{
		read(fd, &c, 1);
		if (c == '\n' || c == EOF || c == 0)
		{
			if (c == EOF || c == 0)
				r[2][0] = '1';
			return;
		}
		process_c(r, c, &idx, &in_w, &word_c);
	}
}
/**
 * process_c - Processes a character and updates arrays accordingly
 * @r: array containing opcode, argument, and end flag
 * @c: character to process
 * @idx: pointer to current index
 * @in_w: pointer to flag indicating if inside a word
 * @word_c: pointer to word count
 * Return: No return value
 */
void process_c(char **r, char c, int *idx, int *in_w, int *word_c)
{
	if (c == ' ' || c == '\t')
	{
		*idx = -1;
		if (*in_w)
		{
			*in_w = 0;
			(*word_c)++;
		}
	}
	else
	{
		*in_w = 1;
	}
	if (*in_w && *word_c == 0)
	{
		r[0][*idx] = c;
	}
	if (*in_w && *word_c == 1)
	{
		r[1][*idx] = c;
	}
}
