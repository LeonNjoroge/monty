#include "monty.h"

/**
  * func_pick - Select the function relating to Monty instruction
  * @s: The instruction to be executed
  * Return: A pointer to the fun or
  * NULL if the function don't exist
  */

void (*func_pick(char *s))(stack_t **, unsigned int)
{
	instruction_t insts[] = {
		{ "nop", none_op },
		{ "sub", subt_op },
		{ "pall", pri_all_op },
		{ "pint", pri_int_op },
		{ "pop", pop_op },
		{ "rotr", rotate_r_op },
		{ "mul", multi_op },
		{ "swap", swap_op },
		{ "add", add_op },
		{ "pstr", pri_str_op },
		{ "rotl", rotate_l_op },
		{ "push_queue", push_que },
		{ "mod", div_2_op },
		{ "pchar", pri_char_op },
		{ "push", push_op },
		{ "div", div_op },
		{ NULL, NULL }
	};

	int m = 0;

	while (insts[m].opcode)
	{
		if (strcmp(s, insts[m].opcode) == 0)
		{
			return (insts[m].f);
		}
		++m;
	}

	return (NULL);
}
