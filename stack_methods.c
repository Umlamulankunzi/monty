#include "monty.h"

/**
 * push - add node to stack
 * @stack: pointer to pointer to head of stack
 * @line_num: line number of opcode being executed
 *
 */
void push(stack_t **stack, unsigned int line_num)
{
	stack_t *node;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_num);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));

	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_app_mem(stack);
		exit(EXIT_FAILURE);
	}

	node->next = *stack;
	node->prev = NULL;
	node->n = data.val;
	if (*stack)
		(*stack)->prev = node;
	*stack = node;
}




/**
 * enqueue - adds nodes to queue
 * @stack: pointer to pointer to head of stack
 * @line_num: line number
 *
 */
void enqueue(stack_t **stack, unsigned int line_num)
{
	stack_t *last, *node;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: stack not found\n", line_num);
		exit(EXIT_FAILURE);
	}

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_app_mem(stack);
		exit(EXIT_FAILURE);
	}

	last = NULL;
	if (*stack)
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = node;
	}
	else
		*stack = node;
	node->prev = last;
	node->next = NULL;
	node->n = data.val;
}




/**
 * pop - deletes top element of stack
 * @stack: pointer to pointer to head of stack
 * @line_num: line number of op_code executed
 *
 */
void pop(stack_t **stack, unsigned int line_num)
{
	stack_t *curr;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	curr = *stack;

	if (curr->next != NULL)
	{
		*stack = curr->next;
		free(curr);
		(*stack)->prev = NULL;
	}
	else
	{
		free(curr);
		*stack = NULL;
	}
}




/**
 * swap - swaps top two elements of the stack
 * @stack: pointer to pointer to head of stack
 * @line_num: line number of op_code executed
 *
 */
void swap(stack_t **stack, unsigned int line_num)
{
	int temp_val;

	if (stack == NULL || *stack == NULL || !((*stack)->next))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	temp_val = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp_val;
}




/**
 * nop - does nothing
 * @stack: pointer to pointer to head of stack
 * @line_num: int line number
 *
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void)stack;
	(void)line_num;
}
