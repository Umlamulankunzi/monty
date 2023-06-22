#include "monty.h"


/**
 * _isalpha - checks if int is acsii code in alphabet
 * @c: int
 * Return: 1 if yes, 0 if no
 */
int _isalpha(int c)
{
	if (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
		return (1);
	return (0);
}




/**
 * get_func - return correct function as per opcode
 * @line: line info and tokens
 * @mem_s: struct maintaining allocd memory
 *
 * Return: function pointer
 */
void (*get_func(line_t line, stack_info *mem_s))(stack_t **, unsigned int)
{
	unsigned int i = 0;
	instruction_t cmds[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", op_add}, {"sub", op_sub}, {"div", op_div},
		{"mul", op_mul}, {"mod", op_mod}, {"nop", nop}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotlop}, {"rotr", rotrop},
		{"stack", change_to_stack}, {"queue", change_to_queue}, {NULL, NULL}
	};

	if (has_comment(line))
		return (nop);

	while (cmds[i].opcode)
	{
		if (strcmp(cmds[i].opcode, line.tokens[0]) == 0)
		{
			push_check(line, mem_s, cmds[i].opcode);
			if (data.flag == 1 &&
			strcmp(cmds[i].opcode, "push") == 0)
			{
				if (line.tokens)
					free(line.tokens);
				return (enqueue);
			}
			free(line.tokens);
			return (cmds[i].f);
		}
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n",
			line.number, line.tokens[0]);
	free(line.tokens);
	free(mem_s->buffer);
	free_app_mem(&(mem_s->stack));
	fclose(mem_s->file);
	free(mem_s);
	exit(EXIT_FAILURE);
}
