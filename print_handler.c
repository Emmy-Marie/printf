#include "main.h"
/**
 * print_handler - Prints an argument based on its type
 * @fmrt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: ind.
 * @buffer: An array of chars containing the buffered output
 * @flags: Flags specified in the format specifier for the character.
 * @width: Width specified in the format specifier for the character.
 * @precision: Precision specified in the format specifier for the character.
 * @size: Size specified in the format specifier for the character.
 * Return: 1 or 2;
 */
int print_handler(const char *fmrt, int *ind, va_list list, char buffer[],
		  int flags, int width, int precision, int size)
{
	int a, unknow_lenght = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned_int}, {'o', print_octal_num},
		{'x', print_hexdec}, {'X', print_upper_hex},
		{'p', print_pointer_value}, {'S', print_non_printable},
		{'r', print_in_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (a = 0; fmt_types[a].fmrt != '\0'; a++)
		if (fmrt[*ind] == fmt_types[a].fmrt)
			return (fmt_types[a].fn(list, buffer,
						flags, width, precision, size));
	if (fmt_types[a].fmrt == '\0')
	{
		if (fmrt[*ind] == '\0')
			return (-1);
		unknow_lenght += write(1, "%%", 1);
		if (fmrt[*ind - 1] == ' ')
			unknow_lenght += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmrt[*ind] != ' ' && fmrt[*ind] != '%')
				--(*ind);
			if (fmrt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_lenght += write(1, &fmrt[*ind], 1);
		return (unknow_lenght);
	}
	return (printed_chars);
}
