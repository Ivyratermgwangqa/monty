#include "new_monty.h"

/**
 * push - function that pushes an integer onto the stack
 * @s: a doubly linked list representing the stack
 * @line: line number in the code (for error messages)
 */
void push(stack_t **s, unsigned int line)
{
	stack_t *new_node;
	int i = 0, num;

	for (; global_var[2][i] != '\0'; i++)
		if (isdigit(global_var[2][i] == 0))
			break;
	if (isdigit(global_var[2][i] == 0) || global_var[2] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line);
		exit(EXIT_FAILURE);
	}
	num = atoi(global_var[2]);
	new_node = malloc(sizeof(stack_t *));
	if (new_node == NULL)
		custom_error_malloc();
	new_node->value = num;
	if (new_node)
		new_node->next = NULL;
	if (s == NULL)
		new_node->prev = NULL;
	else
		new_node->prev = *s;
	*s = new_node;
}
