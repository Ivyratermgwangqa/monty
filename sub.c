#include "monty.h"

/**
 * sub - Subtracts the top element from the second top element of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the code to print error message.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;
	int stack_length = 0;

	stack_length = stack_len(stack);
	if (stack_length < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->prev;
	second->n -= first->n;
	*stack = second;
	free(first);
}
