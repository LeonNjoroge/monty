#ifndef _MONTY_
#define _MONTY_

#define MAX_LINE_LENGTH 1024
/* Constants */
#define SUCSS_OP		0
#define VALID_PARM		0
#define MIN_ARGS		2
#define METH_STACK		300
#define METH_QUEUE		301

/* Common Errors */
#define ERR_BAD_INST	100
#define ERR_BAD_MALL	101
#define ERR_INVLD_PARM	102

/* Usage Errors */
#define ERR_ARG_USG		200
#define ERR_PUSH_USG	201
#define ERR_PINT_USG	202
#define ERR_POP_USG		203
#define ERR_SWAP_USG	204
#define ERR_ADD_USG		205
#define ERR_SUB_USG		206
#define ERR_DIV_USG		207
#define ERR_DIV_ZRO		208
#define ERR_MUL_USG		209
#define ERR_MOD_USG		210
#define ERR_PCH_USG		211
#define ERR_PCH_EMP		212


#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;


void push_op(stack_t **stack, unsigned int param);
void push_que(stack_t **stack, unsigned int param);
void pri_all_op(stack_t **stack, unsigned int line_number);
void pri_int_op(stack_t **stack, unsigned int line_number);
void pop_op(stack_t **stack, unsigned int line_number);
void swap_op(stack_t **stack, unsigned int line_number);
void add_op(stack_t **stack, unsigned int line_number);
void check_args_num(int argn);
FILE *open_file(char *filename);
void check_access_rights(char *filename);
int check_push_param(char *param);
int check_digits(char *s);
unsigned int stack_count(stack_t *stack);
void div_2_op(stack_t **stack, unsigned int line_number);
void pri_char_op(stack_t **stack, unsigned int line_number);
void pri_str_op(stack_t **stack, unsigned int line_number);
void multi_op(stack_t **stack, unsigned int line_number);
int handle_execution(char *op_code, char *op_param, unsigned int line, int m);
void handle_error(int errno, char *opcode, unsigned int line, char *buff);
void handle_cerror(int errno, char *opcode, unsigned int line);
void handle_uerror(int errno, unsigned int line);
void frees_stack(void);
void none_op(stack_t **stack, unsigned int line_number);
void subt_op(stack_t **stack, unsigned int line_number);
void div_op(stack_t **stack, unsigned int line_number);
void handle_more_uerror(int errno, unsigned int line);
void (*func_pick(char *s))(stack_t **, unsigned int);
void rotate_l_op(stack_t **stack, unsigned int line_number);
void rotate_r_op(stack_t **stack, unsigned int line_number);
void pFile(FILE *fd, size_t line_len, unsigned int *line_num, int *op_status);

#endif
