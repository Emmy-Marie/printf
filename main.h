#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
* struct fmrt - Struct op
* @fmrt: The format.
* @fn: The function associated.
*/
struct fmrt
{
char fmrt;
int (*fn)(va_list, char[], int, int, int, int);
};


/**
* typedef struct fmrt fmt_t - Struct op
* @fmrt: The format.
* @fm_t: The function associated.
*/
typedef struct fmrt fmt_t;

int _printf(const char *format, ...);
int print_handler(const char *fmrt, int *i,
va_list print_list, char buffer[], int flags, int width,
int precision, int size);

/****************** FUNCTIONS ******************/

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_unsigned_int(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_octal_num(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexdec(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_upper_hex(va_list types, char buffer[],
int flags, int width, int precision, int size);

int print_hex(va_list types, char map_to[],
char buffer[], int flags, char flag_ch,
int width, int precision, int size);

/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer_value(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int flags_count(const char *format, int *i);
int width_count(const char *format, int *i, va_list print_list);
int precision_count(const char *format, int *i, va_list print_list);
int size_count(const char *format, int *i);

/*Function to print string in reverse*/
int print_in_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int print_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* width handler */
int write_char_handler(char c, char buffer[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);
int write_pointer_value(char buffer[], int ind, int length,
int width, int flags, char padd,
char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hex_code(char, char[], int);
int is_a_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
