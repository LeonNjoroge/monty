#include "monty.h"

/**
 * add_op - Adds the two top elements of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error
 * Return: Nothing
 */
void add_op(stack_t **stack, unsigned int line_number)
{
	unsigned int m = 0, l = 0;
	unsigned int size = 0;
	stack_t *tmp = *stack;

	size = stack_count(*stack);
	if (size < 2)
		handle_error(ERR_ADD_USG, NULL, line_number, NULL);

	m = tmp->n;

	l = tmp->next->n;

	tmp->next->n = m + l;

	*stack = tmp->next;

	free(tmp);

}

/**
 * subt_op - Subtracts top element
 * from the second top element of stack
 *
 * @stack: The head of the stack
 *
 * @line_number: The line on which has error
 * Return: None
 */
void subt_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	unsigned int m = 0, l = 0;
	unsigned int size = 0;

	size = stack_count(*stack);

	if (size < 2)
	{
		handle_error(ERR_SUB_USG, NULL, line_number, NULL);
	}

	m = tmp->n;
	l = tmp->next->n;

	tmp->next->n = l - m;
	*stack = tmp->next;

	free(tmp);

}

/**
 * multi_op - Multi second top element
 * with top element of the stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 * Return: None
 */

void multi_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	unsigned int size = 0;
	unsigned int m = 0, l = 0;

	size = stack_count(*stack);
	if (size < 2)
		handle_error(ERR_MUL_USG, NULL, line_number, NULL);

	m = tmp->n;
	l = tmp->next->n;

	tmp->next->n = l * m;
	*stack = tmp->next;

	free(tmp);
}

/**
 * div_op - Div the sec top element by the top element of the stack
 * @stack: The head of the stack
 * @line_number: The line which has the error
 * Return: None
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	unsigned int size = 0;
	unsigned int m = 0, l = 0;

	size = stack_count(*stack);

	if (size < 2)
		handle_error(ERR_DIV_USG, NULL, line_number, NULL);
	m = tmp->n;
	if (m == 0)
		handle_error(ERR_DIV_ZRO, NULL, line_number, NULL);

	l = tmp->next->n;
	tmp->next->n = l / m;

	*stack = tmp->next;
	free(tmp);

}

/**
 * div_2_op - calculateds the division of the second top element
 * by the top element
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 * Return: None
 */
void div_2_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	unsigned int m = 0, l = 0;
	unsigned int size = 0;

	size = stack_count(*stack);

	if (size < 2)
		handle_error(ERR_MOD_USG, NULL, line_number, NULL);
	m = tmp->n;
	if (m == 0)
		handle_error(ERR_DIV_ZRO, NULL, line_number, NULL);

	l = tmp->next->n;

	tmp->next->n = l % m;

	*stack = tmp->next;
	free(tmp);
}
