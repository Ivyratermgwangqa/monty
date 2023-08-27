#include "monty.h"

/**
 * select_opc - Select the appropriate opcode function.
 * @stack: Pointer to the top of the stack
 * @line_number: Line number in the code
 * Return: 0
 */

int select_opc(stack_t **stack, unsigned int line)
{
	instruction_t op[] = {
		{ "push", push }, { "pall", pall}, { "pop", pop },
		{ "add", add }, { "nop", nop }, { "sub", sub },
		{ "pint", pint }, { "swap", swap },
		{ "mul", mul }, { "div", div_m }, { "pchar", _pchar},
		{ "mod", mod_m }, { "\n", nop }, { " ", nop },
		{ "/t", nop }, { "pstr", pstr_t}, { NULL, NULL }
	};
	int i = 0;

	if (stack == NULL || global_var.token1 == NULL)
		return (0);

	for (; op[i].opcode != NULL; i++)
	{
		if (strcmp(global_var.token1, op[i].opcode) == 0)
		{
			op[i].f(stack, line);
			break;
		}
	}
	return (0);
}
