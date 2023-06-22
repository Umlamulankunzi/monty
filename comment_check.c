#include "monty.h"

run_t_data data = {0, 0};




/**
 * argument_check - verifies argument is valid
 * @token: the argument to be checked
 *
 * Return: true if valid Else false
 */
bool argument_check(char *token)
{
	unsigned int i;

	if (!token)
		return (false);

	for (i = 0; token[i]; i++)
	{
		if (token[0] == '-')
			continue;
		if (token[i] < '0' || token[i] > '9')
			return (false);
	}

	return (true);
}


/**
 * push_check - verifies if cmd is push and update global var if true
 * @line: struct containing line tokens and line number
 * @opcode: opcode to compare
 * @mem_s: struct containing all allocd memory
 *
 */
void push_check(line_t line, stack_info *mem_s, char *opcode)
{
	if ((strcmp(opcode, "push") == 0) && !argument_check(line.tokens[1]))
	{
		free(line.tokens);
		fprintf(stderr, "L%d: usage: push integer\n", line.number);
		free(mem_s->buffer);
		free_app_mem(&(mem_s->stack));
		fclose(mem_s->file);
		free(mem_s);
		exit(EXIT_FAILURE);
	}
	else if (strcmp(opcode, "push") == 0)
		data.val = atoi(line.tokens[1]);
}



/**
 * has_comment - checks if line is a comment
 * @line: struct containing line tokens and line number
 *
 * Return: true if comment, else false
 */
bool has_comment(line_t line)
{
	if (!line.tokens[0])
	{
		free(line.tokens);
		return (true);
	}

	if (line.tokens[0][0] == '#')
	{
		free(line.tokens);
		return (true);
	}

	return (false);
}
