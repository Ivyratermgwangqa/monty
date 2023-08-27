#include "custom_monty.h"

/**
 * custom_error_malloc - prints an error message for memory allocation failure
 */
void custom_error_malloc(void)
{
	fprintf(stderr, "Error: memory allocation failed");
	exit(EXIT_FAILURE);
}

