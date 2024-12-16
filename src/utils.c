#include "../include/argparser.h"
#include "../include/utils.h"

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Free everything and exit the program
 */

void die(const int status)
{
    // Free flag data struct
    free(data.conf_path);
    free(data.flags);

    _exit(status);
}

/**
 * Allocates memory to a pointer ptr of size size
 * @param ptr The pointer to pass in. If zero a new block is allocated
 * @return The pointer to the newly allocated block
 */
void* alloc_mem(void* ptr, size_t size)
{
    // If the pointer is zero, allocate new memory, otherwise resize current block
    if (ptr != 0)
        ptr = realloc(ptr, size);
    else
        ptr = malloc(size);

    if (ptr == NULL)
        _exit(1);

    return ptr;
}