#include "main.h"

/**
 * format_specifier - Handle format specifiers for printf.
 * @format: The format string.
 * @i: The current index in the format string.
 * @args: The va_list containing arguments.
 * @len: Pointer to the length of printed string.
 * Return: 1 if a format specifier was matched, 0 otherwise.
 */
int format_specifier(const char *format, int *i, va_list args, int *len)
{
        convert_match m[] = {
                {"%s", printf_string}, {"%c", printf_char}, {"%%", printf_37},
                {"%d", printf_integer}, {"%i", printf_integer}, {"%b", printf_binary},
                {"%u", printf_unsigned}, {"%o", printf_octal}, {"%x", printf_hexadecimal},
                {"%X", printf_upper_hexadecimal}, {"%S", printf_S}, {"%p", printf_pointer},
                {"%r", printf_revstr}, {"%R", printf_rot13}
        };

        int found_match = 0, j;
        char n_c;

        for (j = 0; j < 14; j++)
        {
                n_c = format[*i + 1];
                if (n_c == ' ' || n_c == '+' || n_c == '#' || n_c == '0' || n_c == '-')
                        n_c = format[*i + 2];

                if (format[*i] == '%' && n_c && n_c == m[j].id[1])
                {
                        *len += m[j].f(args);
                        found_match = 1;
                        break;
                }
        }

        if (found_match)
        {
                n_c = format[*i + 1];
                if (n_c == '+' || n_c == ' ' || n_c == '#' || n_c == '0' || n_c == '-')
                        *i += 3;
                else
                        *i += 2;

                return (1);
        }

        return (0);
}

/**
 * _printf - my printf function.
 * @format: format to a string.
 *
 * Return: length of printed string, or -1 if an error.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1])
		{
			if (format_specifier(format, &i, args, &len))
				continue;
		}

		print_normal(format, &i, &len);
	}

	va_end(args);
	return (len);
}
