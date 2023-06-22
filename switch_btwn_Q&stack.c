#include "monty.h"


/**
 * change_to_stack - changes mode to default mode stack
 * @stack: pointer to pointer to head of stack
 * @line_num: line number
 *
 */
void change_to_stack(stack_t **stack, unsigned int line_num)
{
	(void)line_num;
	(void)stack;
	data.flag = 0;
}



/**
 * change_to_queue - change mode to queue
 * @stack: pointer to pointer to head of stack
 * @line_num: line number
 *
 */
void change_to_queue(stack_t **stack, unsigned int line_num)
{
	(void)line_num;
	(void)stack;
	data.flag = 1;
}
