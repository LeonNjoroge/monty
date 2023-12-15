#include "monty.h"

void processFile(FILE *fd, size_t line_len, unsigned int *line_num, int *op_status)
{
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

char *op_code = strtok(buff, "\t\n ");
if (op_code)
{
if (op_code[0] == '#')
{
++(*line_num);
continue;
}

char *op_param = strtok(NULL, "\t\n ");
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

processFile(fd, line_len, &line_num, &op_status);

frees_stack();
fclose(fd);
return EXIT_SUCCESS;
}