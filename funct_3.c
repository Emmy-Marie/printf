#include "main.h"

/****************** PRINT_POINTER_FUNCTION ******************/
/**
* print_pointer_value - A function that prints the value of a pointer variable
* @types: The argument list.
* @buffer: An array of chars containing the buffered output
* @flags: Flags specified in the format specifier for the character.
* @width: Width specified in the format specifier for the character.
* @precision: Precision specified in the format specifier for the character.
* @size: Size specified in the format specifier for the character.
* Return: Return the number of printed chars.
*/
int print_pointer_value(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char extra_c = 0, padd = ' ';
int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* len=2,for 0x */
unsigned long num_addrs;
char map_to[] = "0123456789abcdef";
void *addrs = va_arg(types, void *);

UNUSED(width);
UNUSED(size);

if (addrs == NULL)
return (write(1, "(nil)", 5));

buffer[BUFF_SIZE - 1] = '\0';
UNUSED(precision);

num_addrs = (unsigned long)addrs;

while (num_addrs > 0)
{
buffer[ind--] = map_to[num_addrs % 16];
num_addrs /= 16;
length++;
}

if ((flags & F_ZERO) && !(flags & F_MINUS))
padd = '0';
if (flags & F_PLUS)
extra_c = '+', length++;
else if (flags & F_SPACE)
extra_c = ' ', length++;

ind++;

/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
return (write_pointer_value(buffer, ind, length,
width, flags, padd, extra_c, padd_start));
}

/*********************** PRINT_NON_PRINTABLE_FUNCTION ***********************/
/**
* print_non_printable - A function that prints ascii codes in hex
*                       of non printable chars
* @types: The argument list.
* @buffer: An array of chars containing the buffered output
* @flags: Flags specified in the format specifier for the character.
* @width: Width specified in the format specifier for the character.
* @precision: Precision specified in the format specifier for the character.
* @size: Size specified in the format specifier for the character.
* Return: Return the number of printed chars.
*/
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
int a = 0, offset = 0;
char *str = va_arg(types, char *);

UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (str == NULL)
return (write(1, "(null)", 6));

while (str[a] != '\0')
{
if (is_printable(str[a]))
buffer[a + offset] = str[a];
else
offset += append_hex_code(str[a], buffer, a + offset);

a++;
}

buffer[a + offset] = '\0';

return (write(1, buffer, a + offset));
}

/************************* PRINT_REVERSE_FUNCTION *************************/
/**
* print_in_reverse - A function that prints a string in reverse.
* @types: The argument list.
* @buffer: An array of chars containing the buffered output
* @flags: Flags specified in the format specifier for the character.
* @width: Width specified in the format specifier for the character.
* @precision: Precision specified in the format specifier for the character.
* @size: Size specified in the format specifier for the character.
* Return: Return the number of printed chars.
*/

int print_in_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char *str;
int a, count = 0;

UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(size);

str = va_arg(types, char *);

if (str == NULL)
{
UNUSED(precision);

str = ")Null(";
}
for (a = 0; str[a]; a++)
;

for (a = a - 1; a >= 0; a--)
{
char z = str[a];

write(1, &z, 1);
count++;
}
return (count);
}
/****************** PRINT_A_STRING_IN_ROT13_FUNCTION ********************/
/**
* print_rot13string - A function that prints a string in rot13.
* @types: The argument list.
* @buffer: An array of chars containing the buffered output
* @flags: Flags specified in the format specifier for the character.
* @width: Width specified in the format specifier for the character.
* @precision: Precision specified in the format specifier for the character.
* @size: Size specified in the format specifier for the character.
* Return: Return the number of printed chars.
*/
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
char x;
char *str;
unsigned int i, j;
int count = 0;
char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

str = va_arg(types, char *);
UNUSED(buffer);
UNUSED(flags);
UNUSED(width);
UNUSED(precision);
UNUSED(size);

if (str == NULL)
str = "(AHYY)";
for (i = 0; str[i]; i++)
{
for (j = 0; in[j]; j++)
{
if (in[j] == str[i])
{
x = out[j];
write(1, &x, 1);
count++;
break;
}
}
if (!in[j])
{
x = str[i];
write(1, &x, 1);
count++;
}
}
return (count);
}
