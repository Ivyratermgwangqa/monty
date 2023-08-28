#include "monty.h"

/**
 * error_on_allocation - prints an error message for memory allocation failure
 */
void error_on_allocation(void)
{
        fprintf(stderr, "Error: memory allocation failed");
        exit(EXIT_FAILURE);
}
