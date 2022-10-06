#include "monty.h"

/**
 * stack_init - initialize an empty stack
 *
 * Return: pointer to the new stack
 */
stack_t *stack_init(void)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = STACK;
	new->prev = NULL;
	new->next = NULL;

	return (new);
}

/**
 * get_op_func - matches an operation with its corresponding function
 * @ops: the operation to be match
 *
 * Return: A pointer to the corresponding function
 */
void (*get_op_func(char *ops))(stack_t **, unsigned int)
{
	instruction_t func[] = {
		{"push", push_handler},
		{"pall", pall_handler},
		{"pint", pint_handler},
		{"pop", pop_handler},
		{"swap", swap_handler},
		{"add", add_handler},
		{"nop", nop_handler},
		{"sub", sub_handler},
		{"div", div_handler},
		{"mul", mul_handler},
		{"mod", mod_handler},
		{"pchar", pchar_handler},
		{"pstr", pstr_handler},
		{"rotl", rotl_handler},
		{"rotr", rotr_handler},
		{"stack", stack_handler},
		{"queue", queue_handler},
		{NULL, NULL}
	};
	int i = 0;
	
	while (func[i].opcode)
		if (strcmp(ops, func[i++].opcode) == 0)
			return (func[--i].f);

	return (NULL);
}

/**
* 
