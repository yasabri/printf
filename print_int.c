#include "main.h"

/**
 * print_unsigned - function that Prints an unsigned number
 * @types: arguments list
 * @width: width
 * @flags: Calculates active flags
 * @buffer: Buffer array to handle print
 * @precision: Precision specification
 * @size: Size
 * Return: chars number that printed
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	unsigned long int x = va_arg(types, unsigned long int);

	x = convert_size_unsgnd(x, size);

	if (x == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (x > 0)
	{
		buffer[z--] = (x % 10) + '0';
		x /= 10;
	}

	z++;

	return (write_unsgnd(0, z, buffer, flags, width, precision, size));
}

/**
 * print_octal - function Print an unsigned number in octal notation
 * @types: arguments list
 * @width: width
 * @flags:  Calculates active flags
 * @buffer: Buffer array to handle print
 * @precision: Precision specification
 * @size: Size
 * Return: chars number that printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int z = BUFF_SIZE - 2;
	unsigned long int x = va_arg(types, unsigned long int);
	unsigned long int init_num = x;

	UNUSED(width);

	x = convert_size_unsgnd(x, size);

	if (x == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (x > 0)
	{
		buffer[z--] = (x % 8) + '0';
		x /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[z--] = '0';

	z++;

	return (write_unsgnd(0, z, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - unsigned number printed in hexadecimal notation
 * @types: arguments list
 * @width: width
 * @flags:  Calculates active flags
 * @buffer: Buffer array to handle print
 * @precision: Precision specification
 * @size: Size
 * Return: chars number that printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - unsigned number printe in upper hexadecimal notation
 * @types: arguments list
 * @width: width
 * @flags:  Calculates active flags
 * @buffer: Buffer array to handle print
 * @precision: Precision specification
 * @size: Size
 * Return: chars number that printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - hexadecimal number printe in lower or upper
 * @types: arguments list
 * @width: width
 * @map_to: Array of values to map the number to
 * @flags: active flags that Calculates
 * @flag_ch: active flags that Calculates
 * @buffer: Buffer array to handle print
 * @width: width
 * @precision: Precision specification
 * @size: Size
 * @size: Size specification
 * Return: chars number that printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int z = BUFF_SIZE - 2;
	unsigned long int x = va_arg(types, unsigned long int);
	unsigned long int init_num = x;

	UNUSED(width);

	x = convert_size_unsgnd(x, size);

	if (x == 0)
		buffer[z--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (x > 0)
	{
		buffer[z--] = map_to[x % 16];
		x /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[z--] = flag_ch;
		buffer[z--] = '0';
	}

	z++;

	return (write_unsgnd(0, z, buffer, flags, width, precision, size));
}
