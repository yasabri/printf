#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int print_37(void);
int _strlen(char *str);
int _strlenc(char *str);
int printf_string(va_list val);
int print_char(va_list val);
int _printf(const char *format, ...);
int _putchar(char c);
int fun_STR(char *buf, int comp, va_list val);
char *conv(unsigned long int n, int b, int uc);


#endif
