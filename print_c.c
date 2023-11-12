#include "main.h"
#include <stdarg.h>

/**
 * print_c - prints a char.
 * @val: arguments.
 * Return: integer.
 */

int print_c(va_list val)
{
	char s;

	s = va_arg(val, int);
	_putchar(s);
	return (1);
}
