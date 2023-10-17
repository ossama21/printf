#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...);

int _printf(const char *format, ...)

{
	va_list args;
	char specifier;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			specifier = *format;
			if (specifier == 'c')
			{
				char c = (char)va_arg(args, int);

				write(1, &c, 1);
				count++;
			}
			else if (specifier == 's')
			{
				char *str = va_arg(args, char *);
				int len = 0;

				while (str[len] != '\0')
				{
					len++;
				}

				write(1, str, len);
				count += len;
			}
			else if (specifier == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else if (specifier == 'd' || specifier == 'i')
			{
				int num = va_arg(args, int);
				char num_str[20];
				int len = 0;

				sprintf(num_str, "%d", num);

				while (num_str[len] != '\0')
				{
					len++;
				}

				write(1, num_str, len);
				count += len;
			}
			else if (specifier == 'u')
			{
				unsigned int num = va_arg(args, unsigned int);
				char num_str[20];
				int len = 0;

				sprintf(num_str, "%u", num);

				while (num_str[len] != '\0')
				{
					len++;
				}

				write(1, num_str, len);
				count += len;
			}
			else if (specifier == 'o')
			{
				unsigned int num = va_arg(args, unsigned int);

				char num_str[20];
				int len = 0;

				sprintf(num_str, "%o", num);
					while (num_str[len] != '\0')
					{
						len++;
					}
				write(1, num_str, len);
				count += len;
			}
			else if (specifier == 'x' || specifier == 'X')
			{
				unsigned int num = va_arg(args, unsigned int);
				char num_str[20];
				int len = 0;

				sprintf(num_str, "%x", num); /**for low_case,use"%x";for upp_case,use"%X"*/
				while (num_str[len] != '\0')
				{
					len++;
				}
				write(1, num_str, len);
				count += len;
			}
			else if (specifier == 'p')
			{
				void *ptr = va_arg(args, void *);
				char addr_str[20];
				int len = 0;

				sprintf(addr_str, "%p", (void *)ptr);

				while (addr_str[len] != '\0')
				{
					len++;
				}

				write(1, addr_str, len);
				count += len;
			}
			else if (specifier == 'r')
			{
				write(1, "[%r]", 4);
				count += 4;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}

		format++;
	}

	va_end(args);

	return (count);
}
