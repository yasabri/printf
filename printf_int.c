#include "main.h"
/**
 * conv - converts to string
 * @n: number
 * @b: base
 * @uc: hexadecimal values in uppercase
 *
 * Return: string
 */
char *conv(unsigned long int n, int b, int uc)
{
	char *re;
	char buf[20];
	char *ptr;

	re = (uc)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ptr = &buf[19];
	*ptr = '\0';
	do {
		*--ptr = re[n % b];
		n /= b;
	} while (n != 0);
	return (ptr);
}
/**
 * fun_STR - prints string, with a caveat
 * @buf: string variable
 * @comp: counter
 * @val: value
 *
 * Return: charcters count
 */
int fun_STR(char *buf, int comp, va_list val)
{
	int i;
	char *r;
	char *str = va_arg(val, char *);

	comp = 0;

	if (!str)
		return (_prtstr("(null)"));
	for (i = 0; str[i]; i++)
	{
		if (str[i] > 0 && (str[i] < 32 || str[i] >= 127))
		{
			_prtstr("\\x");
			comp += 2;
			r = conv(str[i], 16, 0);
			if (!r[1])
				comp += _putchar('0');
			comp += _prtstr(r);
			comp = comp + 4;
		}
		else
			comp += _putchar(str[i]);
	}
	return (_asgn(buf, comp, str));
}
