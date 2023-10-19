#include "monty.h"

/**
 * handle_errors_1 - Outputs appropriate error messages based on error codes.
 * @error_code: The error codes are as follows:
 * (1) => Failure to provide a single valid file to the program.
 * (2) => Inability to open or read the provided file.
 * (3) => Presence of an invalid instruction in the provided file.
 * (4) => Memory allocation failure.
 * (5) => Non-integer parameter passed to the "push" instruction.
 * (6) => Attempting to "pint" with an empty stack.
 * (7) => Attempting to "pop" with an empty stack.
 * (8) => Stack too short for the operation.
 */
void handle_errors_1(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			l_num = va_arg(ag, int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * handle_errors_2 - handles errors.
 * @error_code: The error codes are as follows:
 * (6) => Attempting to "pint" with an empty stack.
 * (7) => Attempting to "pop" with an empty stack.
 * (8) => Stack too short for the operation.
 * (9) => Division by zero.
 */
void handle_errors_2(int error_code, ...)
{
	va_list ag;
	char *op;
	int l_num;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			l_num = va_arg(ag, unsigned int);
			op = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * handle_errors_3 - handles errors.
 * @error_code: The error codes are as follows:
 * (10) => Number inside a node is outside ASCII bounds.
 * (11) => The stack is empty.
 */
void handle_errors_3(int error_code, ...)
{
	va_list ag;
	int l_num;

	va_start(ag, error_code);
	l_num = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
