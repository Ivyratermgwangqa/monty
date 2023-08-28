#ifndef _MONTY_H_
#define _MONTY_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char **global_var;
char **_readop(int fd);
char *malloc_array(void);
void read_and_process(int fd, char **r);
void process_character(char **r, char c, int *idx, int *in_w, int *word_c);
char **initialize_arrays(void);
int select_opc(stack_t **stack, unsigned int line);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void div_m(stack_t **stack, unsigned int line_number);
void error_on_allocation(void);
size_t stack_len(const stack_t *stack);
void op_e(unsigned int line_number, const char *msg);
void free_dlistint(stack_t *stack);
#endif
