#include "monty.h"

/**
 * select_opc - Select the appropriate opcode function.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the code
 * Return: 0
 */

int select_opc(stack_t **stack, unsigned int line_number)
{
	unsigned int i;
	instruction_t op[] = {
		{ "push", push }, { "pall", pall}, { "pop", pop },
		{ "add", add }, { "nop", nop }, { "sub", sub },
		{ "pint", pint }, { "swap", swap }, { "\n", nop },
		{ " ", nop }, { "/t", nop}, { NULL, NULL }
	};
	for (i = 0; op[i].opcode != NULL; i++)
	{
		if (strcmp(global_var[1], op[i].opcode) == 0)
		{
			op[i].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, global_var[1]);
	free(global_var[0]);
	free(global_var[1]);
        free(global_var[2]);
	while (*stack != NULL)
		pop(stack, line_number);
	exit(EXIT_FAILURE);
}
