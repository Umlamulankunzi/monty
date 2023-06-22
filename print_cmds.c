#include "monty.h"




/**
 * pall - prints the data of all nodes in stack
 * @stack: pointer to the head node pointer of stack
 * @line_num: the line number
 *
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *curr;

	(void)line_num;

	curr = *stack;
	while (curr)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}




/**
 * pint - prints top value of stack
 * @stack: pointer to pointer to head of stack
 * @line_num: line number of op_code executed
 */
void pint(stack_t **stack, unsigned int line_num)
{
	stack_t *curr;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	while (curr)
	{
		if (curr->prev == NULL)
			break;
		curr = curr->prev;
	}

	printf("%d\n", curr->n);
}




/**
 * pchar - prints char at top of stack
 * @stack: pointer to the head node pointer of stack
 * @line_num: the line number
 * Return: Nothing.
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	char c;
	stack_t *curr;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	curr = *stack;
	while (curr)
	{
		if (curr->prev == NULL)
			break;
		curr = curr->prev;
	}

	c = curr->n;
	if (_isalpha(curr->n) == 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", c);
}




/**
 * pstr - converts node values to ascii chars and print string of chars
 * @stack: pointer to pointer to head of stack
 * @line_num: the line number
 *
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	char c;
	stack_t *curr = *stack;

	(void)line_num;
	while (curr)
	{
		if (curr->n == 0)
			break;
		if (_isalpha(curr->n) == 0)
			break;

		c = curr->n;
		printf("%c", c);
		curr = curr->next;
	}
	printf("\n");
}
