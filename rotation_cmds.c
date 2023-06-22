#include "monty.h"



/**
 * rotl - rotates the stack to top
 * @stack: pointer to pointer to head of stack
 * @line_num: line number
 *
 */
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *curr;
	int val1, val2;
	(void)line_num;

	if (stack == NULL || *stack == NULL)
	{
		nop(stack, line_num);
		return;
	}

	val1 = (*stack)->n;
	curr = *stack;

	while (curr)
	{
		if (curr->next == NULL)
			break;
		curr = curr->next;
	}

	val2 = curr->n;
	(*stack)->n = val2;
	curr->n = val1;
}




/**
 * rotlop - rotates stack left
 * @stack: pointer to pointer to head of stack
 * @line_num: line number
 *
 */
void rotlop(stack_t **stack, unsigned int line_num)
{
	stack_t *last, *tmp;

	(void)line_num;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	tmp = *stack;
	last = tmp;

	while (last->next)
	{
		last = last->next;
	}

	last->next = tmp;
	tmp->prev = last;
	tmp->next->prev = NULL;
	*stack = tmp->next;
	tmp->next = NULL;
}




/**
 * rotrop - rotates stack right
 * @stack: pointer to pointer to head of stack
 * @line_num: line number
 *
 */
void rotrop(stack_t **stack, unsigned int line_num)
{
	stack_t *last, *tmp;

	(void)line_num;
	if (!stack || !(*stack) || !((*stack)->next))
		return;

	tmp = *stack;
	last = tmp;

	while (last->next)
	{
		last = last->next;
	}

	last->prev->next = NULL;
	last->prev = NULL;
	tmp->prev = last;
	last->next = tmp;
	*stack = last;
}



