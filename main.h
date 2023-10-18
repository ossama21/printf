#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


int _putchar(char c);
int _printf(const char *format, ...);
void print_normal(const char *format, int *i, int *len);
int printf_S(va_list args);
int printf_pointer(va_list args);
int printf_revstr(va_list args);
int printf_rot13(va_list args);
int printf_binary(va_list args);
int printf_unsigned(va_list args);
int printf_octal(va_list args);
int printf_hexadecimal(va_list args);
int printf_upper_hexadecimal(va_list args);
int printf_string(va_list args);
int printf_char(va_list args);
int printf_37(void);
int printf_integer(va_list args);

/**
 * struct format - conversion specifiers match for _printf.
 * @id: pointer to the specifier conversion.
 * @f: function pointer for the conversion specifier.
 *
 */
typedef struct format
{
	const char *id;

	int (*f)();
} convert_match;

#endif
