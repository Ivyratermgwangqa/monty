#include "monty.h"

/**
 * display_stack - display the stack elements
 * @stack: a doubly linked list representing the stack
 * @line: line number in code (for error messages)
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	while (current != NULL)
	{
		printf("%i\n", current->value);
		current = current->prev;
	}
}
