#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;



/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;



/**
 * struct line - line number and parsed token
 * @tokens: array of tokens read from the line
 * @number: the line number
 *
 */
typedef struct line
{
	unsigned int number;
	char **tokens;
} line_t;



/**
 * struct run_time_data - struct containing runtime data info
 * @val: integer value of node
 * @flag: flag to singify if program status is stack or queue
 *
 */
typedef struct run_time_data
{
	int val;
	int flag;
} run_t_data;

extern run_t_data data;



/**
 * struct heap_mem - record of heap allocd memory
 * @stack: pointer to head of stack
 * @buffer: string buffer
 * @file: file pointer
 *
 */
typedef struct heap_mem
{
	stack_t *stack;
	char *buffer;
	FILE *file;
} stack_info;



/* -------GET_FUNC ------ */
void (*get_func(line_t line, stack_info *meta))(stack_t **, unsigned int);
int _isalpha(int c);



/* ------- STACK METHODS -----*/
void push(stack_t **stack, unsigned int line_num);


/* Parse functions */
void parsefile(FILE *file);
void parseline(line_t *line, char *bufferfer);

/* Verification functions */
bool has_comment(line_t line);
void push_check(line_t line, stack_info *meta, char *opcode);

/* Stack manipulation functions */

void pall(stack_t **stack, unsigned int line_num);
void pint(stack_t **stack, unsigned int line_num);
void pop(stack_t **stack, unsigned int line_num);
void swap(stack_t **stack, unsigned int line_num);
void nop(stack_t **stack, unsigned int line_num);
void rotl(stack_t **stack, unsigned int line_num);
void rotlop(stack_t **stack, unsigned int line_num);
void rotrop(stack_t **stack, unsigned int line_num);
void pchar(stack_t **stack, unsigned int line_num);
void pstr(stack_t **stack, unsigned int line_num);
void free_app_mem(stack_t **stack);
void nop(stack_t **stack, unsigned int line_num);
void enqueue(stack_t **stack, unsigned int line_num);
void change_to_queue(stack_t **stack, unsigned int line_num);
void change_to_stack(stack_t **stack, unsigned int line_num);

/* Math functions */
void op_sub(stack_t **stack, unsigned int line_num);
void op_add(stack_t **stack, unsigned int line_num);
void op_div(stack_t **stack, unsigned int line_num);
void op_mul(stack_t **stack, unsigned int line_num);
void op_mod(stack_t **stack, unsigned int line_num);

#endif /* MONTY_H */
