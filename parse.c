#include "monty.h"

/**
 * parseline - tokenizes a line of text, storing it in line struct
 * @line: struct containing line tokenss and line number
 * @bufferfer: string of text read from script file
 *
 * Return: Nothing
 */
void parseline(line_t *line, char *bufferfer)
{
	unsigned int i;
	char *token = NULL;

	line->tokens = malloc(sizeof(char *) * 3);
	if (!line->tokens)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	token = strtok(bufferfer, " '\n'");
	for (i = 0; token && i < 2; i++)
	{
		line->tokens[i] = token;
		token = strtok(NULL, " \n");
	}

	line->tokens[i] = NULL;
}

/**
 * parsefile - reads and parses file one line at a time
 * @file: the script to be read
 *
 * Return: Nothing
 */
void parsefile(FILE *file)
{
	size_t size = 0;
	stack_info *meta = NULL;
	line_t line;

	meta = malloc(sizeof(stack_info));
	if (!meta)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	line.number = 0;
	line.tokens = NULL;

	meta->file = file;
	meta->stack = NULL;
	meta->buffer = NULL;

	while (getline(&(meta->buffer), &size, meta->file) != -1)
	{
		line.number++;
		parseline(&line, meta->buffer);
		if (line.tokens)
			get_func(line, meta)(&(meta->stack), line.number);
	}

	free(meta->buffer);
	free_app_mem(&(meta->stack));
	fclose(meta->file);
	free(meta);
}
