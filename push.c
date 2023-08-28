#include "monty.h"

/**
 * push - function that pushes an integer onto the stack
 * @stack: a doubly linked list representing the stack
 * @line_number: line number in the code (for error messages)
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int i = 0, num;

	for (; global_var[2][i] != '\0'; i++)
		if (isdigit(global_var[2][i] == 0))
			break;
	if (isdigit(global_var[2][i] == 0) || global_var[2] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = atoi(global_var[2]);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		error_on_allocation();
	new_node->n = num;
	new_node->next = *stack;
	new_node->prev = NULL;
	if (stack == NULL)
		new_node->prev = NULL;
	*stack = new_node;
}
