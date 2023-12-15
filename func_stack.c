#include "monty.h"


/**
  * push_op - Adds a new node at start of stack
  * @stack: The head of the stack
  * @param: The value to adds on the stack
  * Return: None
  */

void push_op(stack_t **stack, unsigned int param)
{

	stack_t *node_oth = NULL;
	node_oth = malloc(sizeof(stack_t));

	if (node_oth == NULL)
	{
		handle_error(ERR_BAD_MALL, NULL, 0, NULL);
	}


	node_oth->n = param;

	if (*stack)
	{

		node_oth->next = *stack;

		node_oth->prev = (*stack)->prev;

		(*stack)->prev = node_oth;

		*stack = node_oth;
		return;

	}

	node_oth->next = *stack;

	node_oth->prev = NULL;

	*stack = node_oth;
}

/**
  * push_que - Adds a new node at the end of the stack
  * @stack: The head of the stack
  * @param: The value to adds on the stack
  * Return: None
  */
void push_que(stack_t **stack, unsigned int param)
{
	stack_t *curr = NULL;
	stack_t *node_oth = NULL;

	node_oth = malloc(sizeof(stack_t));

	if (node_oth == NULL)
	{
		handle_error(ERR_BAD_MALL, NULL, 0, NULL);
	}

	node_oth->n = param;

	if (*stack)
	{
		curr = *stack;

		while (curr->next != NULL)
		{
			curr = curr->next;
		}

		node_oth->next = NULL;

		node_oth->prev = curr;

		curr->next = node_oth;
		return;

	}

	node_oth->next = *stack;

	node_oth->prev = NULL;

	*stack = node_oth;
}


/**
 * pop_op - Removes the top element
 * @stack: The head of stack
 * @line_number: The line on which has the error
 * Return: None
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	stack_t *curr = *stack;
 
	if (*stack == NULL)
		handle_error(ERR_POP_USG, NULL, line_number, NULL);

	tmp = curr;
	if (curr->next)
	{
		curr = curr->next;

		curr->prev = tmp->prev;

		*stack = curr;
	}

	else
	{
		*stack = NULL;
	}


	free(tmp);
}



/**
  * rotate_l_op - Rotates the stack to top
  * @stack: The head of the stack
  * @line_number: The line on which has the error
  * Return: None
  */

void rotate_l_op(stack_t **stack, unsigned int line_number)
{
	unsigned int tmp = 0;
	stack_t *curr = *stack;


	(void) line_number;

	if (curr && curr->next)
	{
		while (curr->next != NULL)
		{

			tmp = curr->n;

			curr->n = curr->next->n;

			curr->next->n = tmp;

			curr = curr->next;

		}

	}

}


/**
  * rotate_r_op - rotates the stack to bottom
  * @stack: The head of the stack
  * 
  * @line_number: The line on which has the error
  * Return: None
  */

void rotate_r_op(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	stack_t *final = NULL;

	if (*stack && (*stack)->next)
	{

		final = *stack;

		while (final->next != NULL)
		{
			final = final->next;
		}

		final->prev->next = NULL;

		final->next = *stack;

		*stack = final;

	}

}


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
 * 
 * @line_number: The line on which the error occurred
 *
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