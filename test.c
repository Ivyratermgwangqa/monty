#include "monty.h"

/**
 * main - Process Monty language
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success
 */
char **global_var = NULL;

int main(int argc, char *argv[])
{
	int fd = 0;
	unsigned int line = 0;
	char **tokens = NULL;
	char *filename = NULL;
	stack_t *st = NULL;
	stack_t **stack = &st;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	global_var = (char **)malloc(sizeof(char **) * 3);
	if (!global_var)
	{
		fprintf(stderr, "Error: Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];
	global_var[0] = filename;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		free(global_var);
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		line++;
		tokens = _readopc(fd);
		global_var[1] = tokens[0];
		global_var[2] = tokens[1];

		select_opc(stack, line;

		free(tokens[0]);
		free(tokens[1]);
		if (tokens[2][0] != '0')
		{
		free(tokens[2]);
		free(tokens);
		break;
		}
		free(tokens[2]);
		free(tokens);
	}
	free(global_var);
	close(fd);
	return (0);
}
