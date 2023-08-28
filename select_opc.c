#include "monty.h"

/**
 * select_opc - Select the appropriate opcode function.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the code
 * Return: 0
 */

int select_opc(stack_t **stack, unsigned int line_number)
{
	instruction_t op[] = {
		{ "push", push }, { "pall", pall}, { "pop", pop },
		{ "add", add }, { "nop", nop }, { "sub", sub },
		{ "pint", pint }, { "swap", swap }, { "\n", nop },
		{ " ", nop }, { "/t", nop}, { NULL, NULL }
	};
	int i = 0;

	if (stack == NULL || global_var[1] == NULL)
		return (0);

	for (; op[i].opcode != NULL; i++)
	{
		if (strcmp(global_var[1], op[i].opcode) == 0)
		{
			op[i].f(stack, line);
			break;
		}
	}
	return (0);
}
