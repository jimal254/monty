#include "monty.h"

/**
 * _push - pushes an element to the stack
 * @doubly: double pointer to the head of the list
 * @cline: current line number
 */
void _push(stack_t **doubly, unsigned int cline)
{
    int n;

    if (!vglo.arg)
    {
        dprintf(2, "L%u: usage: push integer\n", cline);
        free_vglo();
        exit(EXIT_FAILURE);
    }

    n = atoi(vglo.arg);
    if (vglo.lifo)
        add_dnodeint(doubly, n);
    else
        add_dnodeint_end(doubly, n);
}

/* Add other functions in opcode_instruc.c as needed */

