#include "monty.h"

/**
 * read_opcode - function that reads opcode and argument from file
 * @fd: file descriptor to read from
 * Return: array containing the opcode, argument, and end flag
 */
char **_readop(int file_descriptor)
{int idx = 0, array_size = 100, flag = 1, in_word = 0, word_count = 0;
        char *operation = NULL, *arg_value = NULL, *end_marker = NULL;
        char **result_array = NULL; 
        char character = 0;

        operation = malloc(array_size);
        arg_value = malloc(array_size);
        end_marker = malloc(1);
        result_array = (char **)malloc(sizeof(char **) * 3);        if (operation == NULL || arg_value == NULL || end_marker == NULL || result_array == NULL)
                error_on_allocation();
        end_marker[0] = '0';

        for (int i = 0; i < array_size; i++)
        {
                operation[i] = 0;
                arg_value[i] = 0;
        }
        for (result_array[0] = operation, result_array[1] = arg_value, result_array[2] = end_marker, idx = 0; flag; idx++)
        {
                read(file_descriptor, &character, 1);                if (character == '\n' || character == EOF || character == 0)                {
                        if (character == EOF || character == 0)
                                end_marker[0] = '1';
                        return result_array;
                }

                if (character == ' ' || character == '\t')
                {
                        idx = -1;
                        if (in_word)
                        {
                in_word = 0;
                word_count++;
            }
        } else {
            in_word = 1;
        }
