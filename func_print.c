#include "monty.h"

/**
 * pri_all_op - Prints all values of the stack form the top
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 * Return: None
 */
void pri_all_op(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *curr = NULL;


	if (*stack)
	{
		curr = *stack;
		while (curr != NULL)
		{

			printf("%d\n", curr->n);

			curr = curr->next;
		}

	}

}

/**
  * pri_char_op - print top of stack char and new line
  * @stack: The head of the stack
  * @line_number: The line has error
  * Return: None
  */
void pri_char_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		handle_error(ERR_PCH_EMP, NULL, line_number, NULL);
		}

	if ((*stack)->n >= 0 && (*stack)->n <= 127)
	{
		printf("%c\n", (*stack)->n);
		}

	else
	{
		handle_error(ERR_PCH_USG, NULL, line_number, NULL);
		}
}


/**
 * pri_int_op - Print int at top of stack and new line
 * @stack: The head of the stack
 * @line_number: The line on which has the error
 * Return: None
 */
void pri_int_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		handle_error(ERR_PINT_USG, NULL, line_number, NULL);
	}

	printf("%d\n", (*stack)->n);

}


/**
  * pri_str_op - print string from top of the stack
  * @stack: The head of the stack
  * @line_number: The line on which has error
  * Return: None
  */

void pri_str_op(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	stack_t *curr = *stack;


	while (curr != NULL)
	{
		if (curr->n == 0 || curr->n < 0 || curr->n > 127)
		{
			break;
		}

		printf("%c", curr->n);

		curr = curr->next;

	}

	printf("\n");

}
