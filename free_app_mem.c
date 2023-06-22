#include "monty.h"


/**
 * free_app_mem - frees all nodes in stack
 * @stack: pointer to pointer to head of stack
 *
 */
void free_app_mem(stack_t **stack)
{
	stack_t *curr = NULL;

	if (stack == NULL || *stack == NULL)
		return;

	while (*stack != NULL)
	{
		curr = (*stack)->next;
		free(*stack);
		*stack = curr;
	}
}
