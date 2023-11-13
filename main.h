#ifndef MAIN_H
#define MAIN_H
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>



/**
 * struct format - converter for printf
 * @ph: type char pointer of the specifier
 * @function: function for the conversion specifier
 *
 */

typedef struct format
{
	char *ph;
	int (*function)();
} convert;

int print_c(va_list val);
int printf_string(va_list val);
int print_s(va_list val);
int *_strcpy(char *dest, char *src);
int print_pointer(va_list val);
int print_unsigned(va_list args);
int _strlenc(const char *s);
int _strlen(char *s);
int print_37(void);
int print_i(va_list args);
int print_d(va_list args);
int _putchar(char c);
int _printf(const char *format, ...);

#endif
