#include "main.h"

/**
 * print_char - character c to stdout
 * @types: the arguments list
 * @width: Width
 * @flags: active flags are Calculate
 * @buffer: Buffer array to handle print
 * @precision: Precision specification
 * @size: Size specifier
 * Return: The number of characters are printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
 * print_string - function that Prints a string
 * @types: the arguments list
 * @width: width
 * @flags: active flags are Calculate
 *  @buffer: Buffer array to handle print
 * @precision: Precision specification
 * @size: Size specifier
 * Return: The number of characters are printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, z;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (z = width - length; z > 0; z--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (z = width - length; z > 0; z--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/**
 * print_percent - percent printed sign
 * @types: the arguments list
 * @width: width
 * @flags: active flags are Calculate
 * @buffer: Buffer array to handle print
 * @precision: Precision specification
 * @size: Size specifier
 * Return: The number of characters are printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * print_int - Print int
 * @types: the arguments list
 * @width: width
 * @flags: active flags are Calculate
 * @buffer: Buffer array to handle print
 * @precision: Precision specification
 * @size: Size specifier
 * Return: The number of characters are printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[x--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[x--] = (num % 10) + '0';
		num /= 10;
	}

	x++;

	return (write_number(is_negative, x, buffer, flags, width, precision, size));
}

/**
 * print_binary - Prints an unsigned number
 * @types: the arguments lise
 * @width: width
 * @flags: Calculates flags that are active
 * @buffer: Buffer array to handle print
 * @precision: Precision
 * @size: Size
 * Return: The number of characters are printed
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, w, sum;
	unsigned int a[32];
	int y;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (w = 1; w < 32; w++)
	{
		m /= 2;
		a[w] = (n / m) % 2;
	}
	for (w = 0, sum = 0, y = 0; w < 32; w++)
	{
		sum += a[w];
		if (sum || w == 31)
		{
			char q = '0' + a[w];

			write(1, &q, 1);
			y++;
		}
	}
	return (y);
}
