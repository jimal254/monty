#include "monty.h"

/**
 * get_opcodes - selects the correct opcode to perform
 * @opc: opcode passed
 *
 * Return: pointer to the function that executes the opcode
 */
void (*get_opcodes(char *opc))(stack_t **stack, unsigned int line_number)
{
    instruction_t instruct[] = {
        {"push", _push},
        {"pall", _pall},
        {"pint", _pint},
        {"pop", _pop},
        {"swap", _swap},
        {"queue", _queue},
        {"stack", _stack},
        {"add", _add},
        {"nop", _nop},
        {"sub", _sub},
        {"mul", _mul},
        {"div", _div},
        {"mod", _mod},
        {"pchar", _pchar},
        {"pstr", _pstr},
        {"rotl", _rotl},
        {"rotr", _rotr},
        {NULL, NULL}
    };

    (void)line_number;

    for (int i = 0; instruct[i].opcode != NULL; i++)
    {
        if (_strcmp(instruct[i].opcode, opc) == 0)
            return (instruct[i].f);
    }

    dprintf(2, "L%u: unknown instruction %s\n", line_number, opc);
    free_vglo();
    exit(EXIT_FAILURE);
}

/* Add other functions in get_opcodes.c as needed */

