#include "monty.h"

/**
 * pFile - Processes a file, executing operations from Monty bytecode
 * @fd: File pointer to the opened Monty bytecode file
 * @line_len: Maximum length of a line in the file
 * @line_num: Pointer to the current line number being processed
 * @op_status: Pointer to the current operation status
 */

void pFile(FILE *fd, size_t line_len, unsigned int *line_num, int *op_status)
{
char *op_code, *op_param;
char *buff = (char *)malloc(line_len);

if (buff == NULL)
{
perror("Error allocating memory");
fclose(fd);
exit(EXIT_FAILURE);
}

while (fgets(buff, line_len, fd) != NULL)
{
if (buff[strlen(buff) - 1] == '\n')
{
buff[strlen(buff) - 1] = '\0';
}

*op_code = strtok(buff, "\t\n ");
if (op_code)
{
if (op_code[0] == '#')
{
++(*line_num);
continue;
}
*op_param = strtok(NULL, "\t\n ");
*op_status = handle_execution(op_code, op_param, *line_num, *op_status);

if (*op_status >= 100 && *op_status < 300)
{
fclose(fd);
handle_error(*op_status, op_code, *line_num, buff);
free(buff);
exit(EXIT_FAILURE);
}
}
++(*line_num);
}

free(buff);
}

/**
 * main - The entry point for the Monty Interpreter
 * @argn: The number of command line arguments
 * @args: An array of strings representing the command line arguments
 *
 * Return: EXIT_SUCCESS on successful execution, EXIT_FAILURE on failure.
 */

int main(int argn, char *args[])
{
FILE *fd = NULL;
size_t line_len = MAX_LINE_LENGTH;
unsigned int line_num = 1;
int op_status = 0;
char *filename = NULL;

filename = args[1];
check_args_num(argn);
fd = open_file(filename);

pFile(fd, line_len, &line_num, &op_status);

frees_stack();
fclose(fd);
return (EXIT_SUCCESS);
}
