#include "monty.h"

/**
 * _realloc - custom realloc implementation
 * @ptr: pointer to the memory previously allocated with malloc
 * @old_size: size of the allocated space for ptr
 * @new_size: new size to allocate
 *
 * Return: pointer to the newly allocated memory
 */
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size)
{
    char *new_ptr;
    unsigned int i;

    if (new_size == old_size)
        return (ptr);

    if (ptr == NULL)
        return (malloc(new_size));

    if (new_size == 0 && ptr != NULL)
    {
        free(ptr);
        return (NULL);
    }

    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
    {
        free(ptr);
        return (NULL);
    }

    for (i = 0; i < old_size && i < new_size; i++)
        new_ptr[i] = ptr[i];

    free(ptr);

    return (new_ptr);
}

/* Add other functions in malloc_functions.c as needed */

