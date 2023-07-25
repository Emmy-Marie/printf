#include "main.h"

/******************** PRINT_UNSIGNED_NUMBER_FUNCTION **********************/
/**
* print_unsigned_int - A function that prints an unsigned integer.
* @types: The argument list.
* @buffer: An array of chars containing the buffered output
* @flags: Flags specified in the format specifier for the character.
* @width: Width specified in the format specifier for the character.
* @precision: Precision specified in the format specifier for the character.
* @size: Size specified in the format specifier for the character.
* Return: Return the number of printed chars.
*/
int print_unsigned_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[a--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[a--] = (num % 10) + '0';
num /= 10;
}

a++;

return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/************* PRINT_UNSIGNED_NUMBER_IN_OCTAL_FUNCTION ***************/
/**
* print_octal_num - A function that prints an unsigned number in octal
* @types: The argument list.
* @buffer: An array of chars containing the buffered output
* @flags: Flags specified in the format specifier for the character.
* @width: Width specified in the format specifier for the character.
* @precision: Precision specified in the format specifier for the character.
* @size: Size specified in the format specifier for the character.
* Return: Return the number of printed chars.
*/
int print_octal_num(va_list types, char buffer[],
int flags, int width, int precision, int size)
{

int a = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(width);

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[a--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[a--] = (num % 8) + '0';
num /= 8;
}

if (flags & F_HASH && init_num != 0)
buffer[a--] = '0';

a++;

return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/************** PRINT_UNSIGNED_NUMBER_IN_HEXADECIMAL_FUNCTION **************/
/**
* print_hexdec - A function that prints an unsigned number in hexadecimal
* @types: The argument list.
* @buffer: An array of chars containing the buffered output
* @flags: Flags specified in the format specifier for the character.
* @width: Width specified in the format specifier for the character.
* @precision: Precision specified in the format specifier for the character.
* @size: Size specified in the format specifier for the character.
* Return: Return the number of printed chars.
*/
int print_hexdec(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hex(types, "0123456789abcdef", buffer,
flags, 'x', width, precision, size));
}

/********** PRINT_UNSIGNED_NUMBER_IN_UPPER_HEXADECIMAL_FUNCTION ***********/
/**
* print_upper_hex - A function that prints an unsigned number in upper hexdec
* @types: The argument list.
* @buffer: An array of chars containing the buffered output
* @flags: Flags specified in the format specifier for the character.
* @width: Width specified in the format specifier for the character.
* @precision: Precision specified in the format specifier for the character.
* @size: Size specified in the format specifier for the character.
* Return: Return the number of printed chars.
*/
int print_upper_hex(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
return (print_hex(types, "0123456789ABCDEF", buffer,
flags, 'X', width, precision, size));
}

/************** PRINT_HEXX_NUM_IN_LOWER_OR_UPPER_FUNCTION **************/
/**
* print_hex - A function that prints a hex number in lower or upper
* @types: The argument list.
* @map_to: Array of chars used to map the hex digits.
* @buffer: An array of chars containing the buffered output
* @flags: Flags specified in the format specifier for the character.
* @flag_ch: Flags specified in the format specifier for hex numbers.
* @width: Width specified in the format specifier for the character.
* @precision: Precision specified in the format specifier for the character.
* @size: Size specified in the format specifier for the character.
* Return: Return the number of printed chars.
*/
int print_hex(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
int a = BUFF_SIZE - 2;
unsigned long int num = va_arg(types, unsigned long int);
unsigned long int init_num = num;

UNUSED(width);

num = convert_size_unsgnd(num, size);

if (num == 0)
buffer[a--] = '0';

buffer[BUFF_SIZE - 1] = '\0';

while (num > 0)
{
buffer[a--] = map_to[num % 16];
num /= 16;
}

if (flags & F_HASH && init_num != 0)
{
buffer[a--] = flag_ch;
buffer[a--] = '0';
}

a++;

return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
