#include "main.h"

/**
* print_normal - prints octal.
* @format: hello to world.
* @i: hello to world!.
* @len: characters printed the number.
*/
void print_normal(const char *format, int *i, int *len)
{
	write(1, &format[*i], 1);
	(*len)++;
	(*i)++;
}
