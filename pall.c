#include "monty.h"

/**
 * pall - display the stack elements
 * @stack: a doubly linked list representing the stack
 * @line_number: number line number in code (for error messages)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		printf("%i\n", current->n);
		current = current->prev;
	}
}
