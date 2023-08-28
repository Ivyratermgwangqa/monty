#include "monty.h"

/**
 * swap - Swap the top two elements of the stack
 * @stack: Pointer to the stack
 * @line_number: Line number of the instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *c;
	int i, sc;

	if (*stack == NULL || (*stack)->next == NULL)
		op_e(line_number, "swap");

	c = (*stack)->next;

	while (c->next != NULL)
		c = c->next;

	i = c->n;
	sc = c->prev->n;

	c->n = sc;
	c->prev->n = i;
}
