#include "../include/utils.h"

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Allocates memory to a pointer ptr of size size
 * @param ptr The pointer to pass in. If zero a new block is allocated
 * @return The pointer to the newly allocated block
 */
void* alloc_mem(void* ptr, size_t size)
{
    void* tmp;

    // If the pointer is zero, allocate new memory, otherwise resize current block
    if (ptr != 0)
    {
        if ((tmp = realloc(ptr, size)) == NULL)
            _exit(12);
    }
    else
    {
        if ((tmp = malloc(size)) == NULL)
            _exit(12);
    }

    return (ptr = tmp);
}
