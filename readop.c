#include "monty.h"

/**
 * _readop - function that reads opcode and argument from file
 * @fd: file descriptor to read from
 * Return: array containing the opcode, argument, and end flag
 */
char **_readop(int fd)
{
	int idx = 0, array_s = 100, f = 1, in_w = 0, word_c = 0;
	char *op = NULL, *arg_val = NULL, *end_m = NULL;
	char **result = NULL;
       	char c = 0;

	op = malloc(array_s);
	arg_val = malloc(array_s);
	end_m = malloc(1);
	result = (char **)malloc(sizeof(char **) * 3);
	if (op == NULL || arg_val == NULL || end_m == NULL || result == NULL)
		error_on_allocation();
	end_m[0] = '0';

	for (int i = 0; i < array_s; i++)
	{
		op[i] = 0;
		arg_val[i] = 0;
	}

	for (result[0] = op, result[1] = arg_val, result[2] = end_m, idx = 0; f; idx++)
	{
		read(file_descriptor, &character, 1);
		if (character == '\n' || character == EOF || character == 0)
		{
			if (character == EOF || character == 0)
				end_m[0] = '1';
			return (result);
	        }

		if (character == ' ' || character == '\t')
		{
			idx = -1;
			if (in_word)
			{
				in_w = 0;
				word_c++;
			}
		} 
		else
		{
			in_w = 1;
		}
		if (in_w && word_c == 0)
			op[idx] = character;
		if (in_w && word_c == 1)arg_val[idx] = character;
	}
    
    return (result);
}
