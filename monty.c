#include "monty.h"

#define MAX_LINE_LENGTH 1024

int main(int argn, char *args[]) {
    FILE *fd = NULL;
    size_t line_len = MAX_LINE_LENGTH;
    unsigned int line_num = 1;
    int op_status = 0;
    char *filename = NULL, *op_code = NULL, *op_param = NULL, *buff = NULL;

    filename = args[1];
    check_args_num(argn);
    fd = open_file(filename);

    buff = (char *)malloc(line_len);
    if (buff == NULL) {
        perror("Error allocating memory");
        fclose(fd);
        return EXIT_FAILURE;
    }

    while (fgets(buff, line_len, fd) != NULL) {
        // Process the content of buff as needed
        // Note: fgets includes the newline character in the string, so you may need to handle it

        if (buff[strlen(buff) - 1] == '\n') {
            // Remove the newline character if present
            buff[strlen(buff) - 1] = '\0';
        }

        op_code = strtok(buff, "\t\n ");
        if (op_code) {
            if (op_code[0] == '#') {
                ++line_num;
                continue;
            }

            op_param = strtok(NULL, "\t\n ");
            op_status = handle_execution(op_code, op_param, line_num, op_status);

            if (op_status >= 100 && op_status < 300) {
                fclose(fd);
                handle_error(op_status, op_code, line_num, buff);
                free(buff);
                return EXIT_FAILURE;
            }
        }

        ++line_num;
    }

    frees_stack();
    free(buff);
    fclose(fd);
    return EXIT_SUCCESS;
}
