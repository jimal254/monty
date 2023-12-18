#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Monty interpreter main function
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
    char *content = NULL;
    size_t size = 0;
    ssize_t read_line;
    FILE *file;
    unsigned int line_number = 0;
    stack_t *doubly = NULL;

    if (argc != 2)
    {
        dprintf(2, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        dprintf(2, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read_line = getline(&content, &size, file)) != -1)
    {
        line_number++;
        execute_line(content, &doubly, line_number);
    }

    free_vglo();
    fclose(file);
    free(content);

    return (EXIT_SUCCESS);
}
