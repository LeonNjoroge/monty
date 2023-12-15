#include "monty.h"


/**
  * stack_count - Counts the number of elements in the stack
  * @stack: The stack to count
  *
  * Return: Number of elements in the stack
  */
unsigned int stack_count(stack_t *stack)
{
	stack_t *current = stack;
	unsigned int lenght = 0;

	while (current != NULL)
	{
		++lenght;
		current = current->next;
	}

	return (lenght);
}


/**
 * swap_op - Swaps the top two elements of stack
 * @stack: The head of the stack
 * @line_number: The line on which the error occurred
 * Return: None
 */

void swap_op(stack_t **stack, unsigned int line_number)
{
	unsigned int size = 0;
	unsigned int tmp = 0;

	size = s;

	ack_count(*stack);

	if (size < 2)
	{
		handle_error(ERR_SWAP_USG, NULL, line_number, NULL);
	}

	if (*stack)
	{
		tmp = (*stack)->n;

		(*stack)->n = (*stack)->next->n;

		(*stack)->next->n = tmp;
	}
}


/**
  * frees_stack - Releases all elements in the stack
  *
  * Return: Nothing
  */
void frees_stack(void)
{
	stack_t *temp = NULL;

	if (head)
	{
		temp = head;

		while (temp)
		{
			head = head->next;
			free(temp);
			temp = head;
		}
	}
}


/**
  * none_op - Does nothing
  * @stack: The head of the stack
  * @line_number: The line on which has the error
  * Return: None
  */
void none_op(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
