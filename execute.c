#include "monty.h"
/**
 * execute - Executes the appropriate function based on the instruction opcode.
 * @content: Line content containing the instruction and arguments.
 * @stack: Pointer to the head of the stack.
 * @counter: Line number being processed.
 * @file: Pointer to the file being read.
 * Return: 0 if successful, 1 if an unknown instruction is encountered.
 */
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
		{"push", ej_add}, {"pall", ej_pall}, {"pint", ej_pint},
		{"pop", ej_pop},
		{"swap", ej_swap},
		{"add", ej_add},
		{"nop", ej_nop},
		{"sub", ej_sub},
		{"div", ej_div},
		{"mul", ej_mul},
		{"mod", ej_mod},
		{"pchar", ej_pchar},
		{"pstr", ej_pstr},
		{"rotl", ej_rotl},
		{"rotr", ej_rotr},
		{"queue", ej_queue},
		{"stack", ej_stack},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{
			opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
