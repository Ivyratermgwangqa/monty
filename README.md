```markdown
# Monty Bytecode Interpreter

This project is an interpreter for Monty ByteCodes files, using a custom stack data structure. It reads Monty byte code files with the `.m` extension and executes the instructions contained in them.

## Data Structures

### struct stack_s

This structure represents a doubly linked list node used for implementing stacks and queues.

```c
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
```

### struct instruction_s

This structure defines an opcode and its associated function for stack and queue operations.

```c
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
```

## Compilation & Output

Compile your code using the following command:

```bash
$ gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

Any output should be printed on `stdout`, and error messages should be printed on `stderr`.

## Usage

Run the `monty` program with the following command:

```bash
$ ./monty <file>
```

Where `<file>` is the path to the Monty byte code file.

## Instructions

1. **push** `<int>`: Pushes an integer onto the stack.
   **pall**: Prints all values on the stack.
Implement the `push` and `pall` opcodes.

#### The push opcode

The `push` opcode pushes an element onto the stack.

Usage: `push <int>`

Where `<int>` is an integer.
- If `<int>` is not an integer or if there is no argument given to `push`, print the error message `L<line_number>: usage: push integer`, followed by a new line, and exit with the status `EXIT_FAILURE`.

#### The pall opcode

The `pall` opcode prints all values on the stack, starting from the top of the stack.

Usage: `pall`
- If the stack is empty, don’t print anything.

1. **pint**: Prints the value at the top of the stack.
Implement the `pint` opcode.

#### The pint opcode

The `pint` opcode prints the value at the top of the stack, followed by a new line.

Usage: `pint`
- If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`.

2. **pop**: Removes the top element of the stack.
Implement the `pop` opcode.

#### The pop opcode

The `pop` opcode removes the top element of the stack.

Usage: `pop`
- If the stack is empty, print the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status `EXIT_FAILURE`.

3. **swap**: Swaps the top two elements of the stack.
Implement the `swap` opcode.

#### The swap opcode

The `swap` opcode swaps the top two elements of the stack.

Usage: `swap`
- If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`.

4. **add**: Adds the top two elements of the stack.
Implement the `add` opcode.

#### The add opcode

The `add` opcode adds the top two elements of the stack.

Usage: `add`
- If the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`.
- The result is stored in the second top element of the stack, and the top element is removed.

5. **nop**: No operation, does nothing.
Implement the `nop` opcode.

#### The nop opcode

The `nop` opcode does nothing.

Usage: `nop`

6. **sub**: Subtracts the top element from the second top element.
Implement the `sub` opcode.

#### The sub opcode

The `sub` opcode subtracts the top element of the stack from the second top element.

Usage: `sub`
- If the stack contains less than two elements, print the error message `L<line_number>: can't sub, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`.
- The result is stored in the second top element of the stack, and the top element is removed.

7. **div**: Divides the second top element by the top element.
Implement the `div` opcode.

#### The div opcode

The `div` opcode divides the second top element of the stack by the top element.

Usage: `div`
- If the stack contains less than two elements, print the error message `L<line_number>: can't div, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`.
- The result is stored in the second top element of the stack, and the top element is removed.
- If the top element of the stack is 0, print the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`.

8. **mul**: Multiplies the top two elements of the stack.
Implement the `mul` opcode.

#### The mul opcode

The `mul` opcode multiplies the second top element of the stack with the top element.

Usage: `mul`
- If the stack contains less than two elements, print the error message `L<line_number>: can't mul, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`.
- The result is stored in the second top element of the stack, and the top element is removed.

9. **mod**: Computes the remainder of the division of the second top element by the top element.
Implement the `mod` opcode.

#### The mod opcode

The `mod` opcode computes the remainder of the division of the second top element by the top element.

Usage: `mod`
- If the stack contains less than two elements, print the error message `L<line_number>: can't mod, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`.
- The result is stored in the second top element of the stack, and the top element is removed.
- If the top element of the stack is 0, print the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`.

10. **comments**: Comments start with a '#' symbol.
Implement the `comments` feature.

#### The comments feature

In Monty, lines that begin with a `#` are treated as comments and are ignored.

Usage: Simply start a line with `#` to create a comment.

11. **pchar**: Prints the character at the top of the stack.
Implement the `pchar` opcode.

#### The pchar opcode

The `pchar` opcode prints the character at the top of the stack as an ASCII character, followed by a new line.

Usage: `pchar`
- The integer stored at the top of the stack is treated as the ASCII value of the character to be printed.
- If the value is not in the ASCII table, print the error message `L<line_number>: can't pchar, value out of range`, followed by a new line, and exit with the status `EXIT_FAILURE`.
- If the stack is empty, print the error message `L<line_number>: can't pchar, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`.

12. **pstr**: Prints the string starting from the top of the stack.
Implement the `pstr` opcode.

#### The pstr opcode

The `pstr` opcode prints a string starting at the top of the stack, treating each element as an ASCII value, until reaching a 0 value or an out-of-range value.

Usage: `pstr`
- The integer stored in each element of the stack is treated as the ASCII value of the character to be printed.
- The string stops when:
  - The stack is empty
  - The value of the element is 0
  - The value of the element is not in the ASCII table

### Compilation & Running

Compile your code using the following command:

## Testing

We encourage you to work together on a set of tests to ensure the correctness of your implementation.

## Contributing

Feel free to contribute to this project by submitting pull requests or opening issues if you find any bugs or improvements.

```
