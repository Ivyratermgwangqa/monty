#include "monty.h"

/**
 * pint - Prints the value of the first element in the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number in the script.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("%i\n", (*stack)->n);
	}
}
