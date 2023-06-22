#include "monty.h"



/**
 * op_add - adds top two elements of stack
 * @stack: pointer to pointer to head of stack
 * @line_num: line number
 *
 */
void op_add(stack_t **stack, unsigned int line_num)
{
	stack_t *curr;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	curr->next->n += curr->n;
	*stack = curr->next;
	(*stack)->prev = NULL;
	free(curr);
}



/**
 * op_sub - subtracts top two elements, stores result in second element
 * @stack: pointer pointr to head of stack
 * @line_num: line number
 *
 */
void op_sub(stack_t **stack, unsigned int line_num)
{
	stack_t *curr;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	curr->next->n -= curr->n;
	*stack = curr->next;
	(*stack)->prev = NULL;
	free(curr);
}




/**
 * op_div - divides the top two elements and stores it in second element
 * @stack: pointer to pointer of head node of stack
 * @line_num: line number
 *
 */
void op_div(stack_t **stack, unsigned int line_num)
{
	stack_t *curr;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	curr->next->n /= curr->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(curr);
}





/**
 * op_mul - multiply top two elements & stores result in second element
 * @stack: pointer to the head node pointer of stack
 * @line_num: the line number
 * Return: Nothing.
 */
void op_mul(stack_t **stack, unsigned int line_num)
{
	stack_t *curr;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	curr->next->n *= curr->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(curr);
}





/**
 * op_mod - computes rest of division of second top by top element stack.
 * @stack: pointer to pointer to head of stack
 * @line_num: line number
 *
 */
void op_mod(stack_t **stack, unsigned int line_num)
{
	stack_t *curr;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	curr->next->n %= curr->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(curr);
}
