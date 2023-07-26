#include "main.h"

void print_buffer(char buffer[], int *buffer_index);
/**
* _printf - A function that prints formatted output to the console.
* @format: A string containing regular chars and format specifiers.
* Return: The function returns the total number of chars printed.
*/
int _printf(const char *format, ...)
{
	int a, printed_handle = 0, total_chars_printed = 0;
	int precision, size, width, flags, buffer_index = 0;
	va_list print_list; /* Naming our list */
	char buffer[BUFF_SIZE];

	if (format == NULL) /* Checking if format string is NULL */
		return (-1);

	va_start(print_list, format); /* Initialize list */

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buffer_index++] = format[a];
			if (buffer_index == BUFF_SIZE)
				print_buffer(buffer, &buffer_index);

			total_chars_printed++;
		}
		else
		{
			print_buffer(buffer, &buffer_index);
			flags = flags_count(format, &a);
			width = width_count(format, &a, print_list);
			precision = precision_count(format, &a, print_list);
			size = size_count(format, &a);
			++a;
			printed_handle = print_handler(format, &a, print_list,
						       buffer, flags, width, precision, size);
			if (printed_handle == -1)
				return (-1);
			total_chars_printed += printed_handle;
		}
	}

	print_buffer(buffer, &buffer_index);

	va_end(print_list);

	return (total_chars_printed);
}

/**
* print_buffer - A function that prints buffer contents to the standard output.
* @buffer: An array of chars containing the buffered output
* @buffer_index: Length of buffer. Index to add next char.
*/
void print_buffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0; /* Reset the buffer index to zero */
}
