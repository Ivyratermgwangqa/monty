#include "monty.h"
/**
 * pop - Removes the top element from the stack.
 * @stack: A pointer to the top of the stack.
 * @line_number: The current line number.
 *
 * Return: No return value.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL;
	stack_t *temp2 = NULL;
	int idx1 = 0, idx2 = 0, flag = 0;

	if (stack == NULL || *stack == NULL)
	{
		free_dlistint(*stack);
		pop_e(line_number);
	}
	temp = *stack;
	while (temp->next != NULL)
	{
		temp = temp->next;
		idx1++;
		flag = 1;
	}
	temp2 = *stack;
	while (idx2 < (idx1 - 1))
	{
		temp2 = temp2->next;
		idx2++;
	}
	if (idx1 == 0 && flag == 0)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	else
	{
		temp2->next = NULL;
		free(temp);
		temp = NULL;
		return;
	}
}
