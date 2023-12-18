nclude "monty.h"

/**
 * add_dnodeint_end - adds a new node at the end of a doubly linked list
 * @head: double pointer to the head of the list
 * @n: value to be added to the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
    stack_t *new_node, *last = *head;

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        dprintf(2, "Error: malloc failed\n");
        free_vglo();
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->next = NULL;

    if (!*head)
    {
        new_node->prev = NULL;
        *head = new_node;
        return (new_node);
    }

    while (last->next)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;

    return (new_node);
}

/* Add other functions in doubly_functions.c as needed */

